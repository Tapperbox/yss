////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined(STM32F100xB) || defined(STM32F100xE) || \
	defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined(STM32F102x6) || defined(STM32F102xB) || \
	defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) || \
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/clock/drv_st_clock_type_B_register.h>
#include <drv/clock/drv_st_power_type_B_register.h>

#if defined(RCC)
drv::Clock clock;
#endif

namespace drv
{
	unsigned char gHseFreq __attribute__ ((section (".non_init")));
	unsigned long gPllFreq __attribute__ ((section (".non_init")));

	static const unsigned long gPpreDiv[8] = {1, 1,	1, 1, 2, 4, 8, 16};
	static const unsigned long gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

	bool Clock::enableHse(unsigned char hseMhz)
	{
		unsigned long hse = (unsigned long)hseMhz * 1000000;
		gHseFreq = hseMhz;
		
#if defined(YSS_PERI_REPORT)
		debug_printf("\n########## HSE 장치 설정 ##########\n\n");
		debug_printf("외부 크리스탈 클럭 = %d MHz\n", hseMhz);
#endif

		if(hse < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hse)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("HSE 클럭이 입력 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", ec::clock::hse::HSE_MIN_FREQ / 1000, hse / 1000, ec::clock::hse::HSE_MAX_FREQ / 1000);
#endif
			return false;
		}

		setRccHseEn(true);

		for(unsigned int i=0;i<10000;i++)
		{
			if(getRccHseReady())
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 완료.\n");
#endif
				return true;
			}
		}

#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif
		return false;
	}

	bool Clock::enableLsi(bool en)
	{
		setRccLsiEn(en);
		if(en == true)
		{
			for(unsigned short i=0;i<10000;i++)
			{
				if(getRccLsiReady())
					return true;
			}
		}
		else
		{
			return true;
		}

		return false;
	}

	bool Clock::enableLse(bool en)
	{
		setRccLseEn(en);
		if(en == true)
		{
			for(unsigned short i=0;i<10000;i++)
			{
				if(getRccLseReady())
					return true;
			}
		}
		else
		{
			return true;
		}

		return false;
	}

	bool Mainpll::enable(unsigned char src, unsigned char xtpre, unsigned char mul)
	{
		unsigned long pll;

#if defined(YSS_PERI_REPORT)
		debug_printf("\n########## Main PLL 장치 설정 ##########\n\n");
#endif

		using namespace define::clock::sysclk;
		if(getRccSysclkSw()	== src::PLL)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("장치가 이미 활성화되어 시스템 클럭으로 설정되어 있습니다.\n");
#endif
			goto error;
		}

		using namespace ec::clock::pll;
		if(src > PLL_SRC_MAX)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("클럭 소스의 선택 범위를 초과했습니다.\n");
#endif
			goto error;
		}

		if(xtpre > PLL_XTPRE_MAX)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("인자 xtpre의 설정이 허용 범위를 초과했습니다. %d(user) < %d(max).\n", xtpre, PLL_XTPRE_MAX);
#endif
			goto error;
		}

		if(mul > PLL_MUL_MAX)
        {
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("인자 mul의 설정이 허용 범위를 초과했습니다. %d(user) < %d(max).\n", mul, PLL_MUL_MAX);
#endif
			goto error;
		}

		if(src == src::HSE)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("클럭 소스 = HSE 외부 크리스탈\n");
#endif
			if(getRccHseReady() == true)
				pll = (unsigned long)gHseFreq*1000000;
			else
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 실패.\n");
				debug_printf("HSE 클럭이 활성화되지 않았습니다.\n");
#endif
				goto error;
			}
			if(xtpre == define::clock::pll::xtpre::DIV2)
				pll >>= 1;
		}
		else
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("클럭 소스 = HSI 내부 RC 8MHz\n");
#endif
			pll = ec::clock::hsi::FREQ / 2;
		}

		if(pll < PLL_IN_MIN_FREQ || PLL_IN_MAX_FREQ < pll)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("Main PLL의 입력 주파수가 허용 범위를 벗어났습니다. %d(min) < %d(user) < %d(max).\n", PLL_IN_MIN_FREQ, pll, PLL_IN_MAX_FREQ);
#endif
			goto error;
		}

		mul = mul - 2;
		if(mul > 14)
			mul = 14;

		pll *= (mul + 2);
		if(pll < PLL_OUT_MIN_FREQ || PLL_OUT_MAX_FREQ < pll)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("Main PLL의 설정 주파수가 허용 범위를 벗어났습니다. %d(min) < %d(user) < %d(max).\n", PLL_IN_MIN_FREQ, pll, PLL_IN_MAX_FREQ);
#endif
			goto error;
		}

		setRccPllMul(mul);
		setRccPllXtpre(xtpre);
		setRccPllSrc(src);

		setRccMainPllOn(true);

		for(unsigned short i=0;i<10000;i++)
		{
			if(getRccMainPllReady())
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("PLL = %d kHz\n", pll/1000);
				debug_printf("장치 설정 완료.\n");
#endif
				gPllFreq = pll;
				return true;
			}
		}

#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif

error:
		gPllFreq = 0;
		return false;
	}

	bool Clock::setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2)
	{
		unsigned long clk, ahbClk,	apb1Clk, apb2Clk, adcClk;

#if defined(YSS_PERI_REPORT)
		debug_printf("\n##########  시스템 클럭 설정 ##########\n\n");
#endif

		using namespace define::clock::sysclk::src;
		switch(sysclkSrc)
		{
		case HSI :
#if defined(YSS_PERI_REPORT)
			debug_printf("클럭 소스 = HSI 내부 RC 8MHz\n");
#endif
			clk = ec::clock::hsi::FREQ;
			break;
		case HSE :
#if defined(YSS_PERI_REPORT)
			debug_printf("클럭 소스 = HSE 외부 크리스탈\n");
#endif
			if(getRccHseReady() == false)
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 실패.\n");
				debug_printf("외부 크리스탈이 현재 동작중이 아닙니다. 먼저 외부 크리스탈을 활성화 해주세요.\n");
#endif
				return false;
			}
			clk = gHseFreq * 1000000;
			break;
		case PLL :
#if defined(YSS_PERI_REPORT)
			debug_printf("클럭 소스 = PLL\n");
#endif
			if(getRccMainPllReady()	== false)
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 실패.\n");
				debug_printf("PLL이 현재 동작중이 아닙니다. 먼저 PLL을 활성화 해주세요.\n");
#endif
				return false;
			}
			clk = gPllFreq;
			break;
		default :
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 실패.\n");
				debug_printf("지정된 클럭 소스가 유효하지 않습니다.\n");
#endif
			return false;
		}

		ahbClk = clk / gHpreDiv[ahb];
		if(ahbClk > ec::clock::sysclk::MAX_FREQ)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("Sysclk 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", ahbClk, ec::clock::sysclk::MAX_FREQ);
#endif
			return false;
		}

		apb1Clk = ahbClk / gPpreDiv[apb1];
		if(apb1Clk	> ec::clock::apb1::MAX_FREQ)
        {
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("APB1 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", apb1Clk, ec::clock::apb1::MAX_FREQ);
#endif
			return false;
		}

		apb2Clk = ahbClk / gPpreDiv[apb2];
		if(apb2Clk	> ec::clock::apb2::MAX_FREQ)
        {
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("APB2 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", apb2Clk, ec::clock::apb2::MAX_FREQ);
#endif
			return false;
		}

		adcClk = apb2Clk / (ec::clock::adc::MAX_FREQ / 1000);
		if(adcClk >= 1000)
		{
			adcClk /= 1000;
			adcClk += 1;
			if(adcClk <= 2)
				setRccAdcpre(0);
			else if(adcClk <= 4)
				setRccAdcpre(1);
			else if(adcClk <= 6)
				setRccAdcpre(2);
			else if(adcClk <= 8)
				setRccAdcpre(3);
			else
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 실패.\n");
				debug_printf("ADC 분주비 설정에 실패했습니다.\n");
#endif
				return false;
			}
		}

		setRccHpre(ahb);
		setRccPpre1(apb1);
		setRccPpre2(apb2);

		flash.setLatency(ahbClk);
		setRccSysclkSw(sysclkSrc);

#if defined(YSS_PERI_REPORT)
		debug_printf("Sysclk = %d kHz\n", ahbClk/1000);
		debug_printf("APB1 = %d kHz\n", apb1Clk/1000);
		debug_printf("APB2 = %d kHz\n", apb2Clk/1000);
		debug_printf("장치 설정 완료.\n");
#endif

		return true;
	}

	unsigned long Clock::getSysClkFreq(void)
	{
		unsigned long clk;

		switch(getRccSysclkSw())
		{
		case define::clock::sysclk::src::HSI :
			clk = ec::clock::hsi::FREQ;
			break;
		case define::clock::sysclk::src::HSE :
			clk = gHseFreq;
			break;
		case define::clock::sysclk::src::PLL :
			clk = gPllFreq;
			break;
		}

		clk /= gHpreDiv[getRccHpre()];

		return clk;
	}

	unsigned long Clock::getApb1ClkFreq(void)
	{
		unsigned long clk = getSysClkFreq() / gPpreDiv[getRccPpre1()];
		return clk;
	}

	unsigned long Clock::getApb2ClkFreq(void)
	{
		unsigned long clk = getSysClkFreq() / gPpreDiv[getRccPpre2()];
		return clk;
	}

	unsigned long Clock::getTimerApb1ClkFreq(void)
	{
		unsigned char pre = getRccPpre1();
		unsigned long clk = clock.getSysClkFreq() / gPpreDiv[pre];
		if(gPpreDiv[pre] > 1)
			clk <<= 1;
		return clk;
	}

	unsigned long Clock::getTimerApb2ClkFreq(void)
	{
		unsigned char pre = getRccPpre2();
		unsigned long clk = clock.getSysClkFreq() / gPpreDiv[pre];
		if(gPpreDiv[pre] > 1)
			clk <<= 1;
		return clk;
	}

}

#endif
