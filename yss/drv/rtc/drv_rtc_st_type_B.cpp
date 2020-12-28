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
//  주담당자 : 아이구 (mymy49@nate.com) 2018.02.08 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <util/TimeLapse.h>
#include <yss/thread.h>

#include <drv/peripherals.h>
#include <drv/rtc/drv_st_rtc_type_A_register.h>

static void reset(void)
{
    PWR->CR |= PWR_CR_DBP_Msk;
    RCC->BDCR |= RCC_BDCR_BDRST_Msk;
    RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
    PWR->CR &= ~PWR_CR_DBP_Msk;
}

drv::Rtc rtc(RTC, 0, 0, reset);

namespace drv
{
Rtc::Rtc(RTC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
}

unsigned int Rtc::getCounter(void)
{
	return 0;
}

bool Rtc::setCounter(unsigned int cnt)
{
	return false;
}

inline bool enableClock(unsigned char src);

bool Rtc::init(unsigned char src, unsigned int freq)
{
    signed int apre = 0x7f, spre;
	unsigned int reg;
	TimeLapse timelapse;

	if(src != (RCC->BDCR & RCC_BDCR_RTCSEL_Msk) >> RCC_BDCR_RTCSEL_Pos)
	{
		PWR->CR |= PWR_CR_DBP_Msk;
		RCC->BDCR |= RCC_BDCR_BDRST_Msk;
		RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
		
		enableClock(src);
		
		reg = RCC->BDCR;
		reg &= ~RCC_BDCR_RTCSEL_Msk;
		reg |= (src << RCC_BDCR_RTCSEL_Pos & RCC_BDCR_RTCSEL_Msk) | RCC_BDCR_RTCEN_Msk;
		RCC->BDCR = reg;
	}
//    unprotect();


	return false;
}

void Rtc::refresh(void)
{

}

void Rtc::unprotect(void)
{
    //PWR->CR |= PWR_CR_DBP_Msk;
    //RTC->WPR = 0xca;
    //RTC->WPR = 0x53;
    //RTC->ISR |= RTC_ISR_INIT_Msk;
}

inline void enableLsiClock(void)
{
    RCC->CSR |= RCC_CSR_LSION_Msk;

    for (unsigned long i = 0; i < 1000000; i++)
    {
        if (RCC->CSR & RCC_CSR_LSIRDY_Msk)
            break;
        ;
    }
}

inline void enableLseClock(void)
{
	TimeLapse timelapse;
    RCC->BDCR |= RCC_BDCR_LSEON_Msk;

    while(1)
    {
        if (RCC->BDCR & RCC_BDCR_LSERDY_Msk)
            return;
		if(timelapse.getMsec() > 3000)
			return;
    }
}

inline bool enableClock(unsigned char src)
{
    switch (src)
    {
    case define::rtc::clockSrc::NO_CLOCK:
        return false;
    case define::rtc::clockSrc::LSE:
        if (~RCC->BDCR & RCC_BDCR_LSERDY_Msk)
            enableLseClock();
        break;
    case define::rtc::clockSrc::LSI:
        if ((RCC->CSR & RCC_CSR_LSIRDY_Msk) == 0)
            enableLsiClock();
        break;
    case define::rtc::clockSrc::HSE:
        return false;
    }

    return true;
}

/*
inline bool enableClock(unsigned char src, unsigned char lseDrive);
inline void setClockSrc(unsigned char src);
inline unsigned char getClockSrc(void);


bool Rtc::init(unsigned char src, unsigned int freq, unsigned char lseDrive)
{
    signed int apre = 0x7f, spre;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();

    enableClock(src, lseDrive);

    if (getClockSrc() != src)
    {
        reset();
        unprotect();
    }

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

    if ((RCC->BDCR & RCC_BDCR_RTCEN_Msk) == 0)
    {
        RCC->BDCR |= RCC_BDCR_RTCEN_Msk;

#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                   \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                   \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                           \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                           \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                           \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

    if ((RCC->CSR & RCC_CSR_RTCEN_Msk) == 0)
    {
        RCC->CSR |= RCC_CSR_RTCEN_Msk;

#endif

        setClockSrc(src);

        while (!(RTC->ISR & RTC_ISR_INITF_Msk))
        {
            thread::yield();
            if (time::getRunningMsec() >= endTime)
                return false;
        }

        for (apre = 0x7f; apre; apre >>= 1)
        {
            if ((freq & apre) == 0x00)
                break;
        }
        spre = freq / (apre + 1) - 1;

        RTC->CR |= RTC_CR_BYPSHAD_Msk;
        RTC->PRER = spre << RTC_PRER_PREDIV_S_Pos | apre << RTC_PRER_PREDIV_A_Pos;
    }

    protect();

    return true;
}


inline void enableLsiClock(void)
{
    RCC->CSR |= RCC_CSR_LSION_Msk;

    for (unsigned long i = 0; i < 1000000; i++)
    {
        if (RCC->CSR & RCC_CSR_LSIRDY_Msk)
            break;
        ;
    }
}

inline bool enableClock(unsigned char src, unsigned char lseDrive)
{
    switch (src)
    {
    case define::rtc::clockSrc::NO_CLOCK:
        return false;
    case define::rtc::clockSrc::LSE:
#if defined(RCC_BDCR_LSEDRV)
        RCC->BDCR &= ~RCC_BDCR_LSEDRV_Msk;
        RCC->BDCR |= lseDrive << RCC_BDCR_LSEDRV_Pos;
#endif

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

        if ((RCC->BDCR & RCC_BDCR_LSERDY_Msk) == 0)
            enableLseClock();

#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                   \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                   \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                           \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                           \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                           \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

        if ((RCC->CSR & RCC_CSR_LSERDY_Msk) == 0)
            enableLseClock();

#endif

        break;
    case define::rtc::clockSrc::LSI:
        if ((RCC->CSR & RCC_CSR_LSIRDY_Msk) == 0)
            enableLsiClock();
        break;
    case define::rtc::clockSrc::HSE:
        return false;
    }

    return true;
}

inline void setClockSrc(unsigned char src)
{
#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

    RCC->BDCR &= ~RCC_BDCR_RTCSEL_Msk;
    RCC->BDCR |= src << RCC_BDCR_RTCSEL_Pos;

#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                   \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                   \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                           \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                           \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                           \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

    RCC->CSR &= ~RCC_CSR_RTCSEL_Msk;
    RCC->CSR |= src << RCC_CSR_RTCSEL_Pos;

#endif
}

inline unsigned char getClockSrc(void)
{
#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

    return (RCC->BDCR & RCC_BDCR_RTCSEL_Msk) >> RCC_BDCR_RTCSEL_Pos;

#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                   \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                   \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                           \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                           \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                           \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

    return (RCC->CSR & RCC_CSR_RTCSEL_Msk) >> RCC_CSR_RTCSEL_Pos;

#endif
}

void Rtc::refresh(void)
{
}

unsigned char Rtc::getYear(void)
{
    return ((RTC->DR & RTC_DR_YT_Msk) >> RTC_DR_YT_Pos) * 10 + ((RTC->DR & RTC_DR_YU_Msk) >> RTC_DR_YU_Pos);
}

bool Rtc::setYear(unsigned char year)
{
    unsigned long dr = RTC->DR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    dr &= ~(RTC_DR_YT_Msk | RTC_DR_YU_Msk);
    dr |= ((year / 10 % 10) << RTC_DR_YT_Pos) | ((year % 10) << RTC_DR_YU_Pos);
    RTC->DR = dr;

    protect();
    return true;
}

unsigned char Rtc::getMonth(void)
{
    return ((RTC->DR & RTC_DR_MT_Msk) >> RTC_DR_MT_Pos) * 10 + ((RTC->DR & RTC_DR_MU_Msk) >> RTC_DR_MU_Pos);
}

bool Rtc::setMonth(unsigned char month)
{
    unsigned long dr = RTC->DR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    dr &= ~(RTC_DR_MT_Msk | RTC_DR_MU_Msk);
    dr |= ((month / 10 % 10) << RTC_DR_MT_Pos) | ((month % 10) << RTC_DR_MU_Pos);
    RTC->DR = dr;

    protect();
    return true;
}

unsigned char Rtc::getDay(void)
{
    return ((RTC->DR & RTC_DR_DT_Msk) >> RTC_DR_DT_Pos) * 10 + ((RTC->DR & RTC_DR_DU_Msk) >> RTC_DR_DU_Pos);
}

bool Rtc::setDay(unsigned char day)
{
    unsigned long dr = RTC->DR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    dr &= ~(RTC_DR_DT_Msk | RTC_DR_DU_Msk);
    dr |= ((day / 10 % 10) << RTC_DR_DT_Pos) | ((day % 10) << RTC_DR_DU_Pos);
    RTC->DR = dr;

    protect();
    return true;
}

unsigned char Rtc::getWeekDay(void)
{
    return (RTC->DR & RTC_DR_WDU_Msk) >> RTC_DR_WDU_Pos;
}

bool Rtc::setWeekDay(unsigned char weekDay)
{
    unsigned long dr = RTC->DR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    dr &= ~RTC_DR_WDU_Msk;
    dr |= weekDay << RTC_DR_WDU_Pos;
    RTC->DR = dr;

    protect();
    return true;
}

unsigned char Rtc::getHour(void)
{
    return ((RTC->TR & RTC_TR_HT_Msk) >> RTC_TR_HT_Pos) * 10 + ((RTC->TR & RTC_TR_HU_Msk) >> RTC_TR_HU_Pos);
}

bool Rtc::setHour(unsigned char hour)
{
    unsigned long tr = RTC->TR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    tr &= ~(RTC_TR_HT_Msk | RTC_TR_HU_Msk);
    tr |= ((hour / 10 % 10) << RTC_TR_HT_Pos) | ((hour % 10) << RTC_TR_HU_Pos);
    RTC->TR = tr;

    protect();
    return true;
}

unsigned char Rtc::getMin(void)
{
    return ((RTC->TR & RTC_TR_MNT_Msk) >> RTC_TR_MNT_Pos) * 10 + ((RTC->TR & RTC_TR_MNU_Msk) >> RTC_TR_MNU_Pos);
}

bool Rtc::setMin(unsigned char min)
{
    unsigned long tr = RTC->TR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    tr &= ~(RTC_TR_MNT_Msk | RTC_TR_MNU_Msk);
    tr |= ((min / 10 % 10) << RTC_TR_MNT_Pos) | ((min % 10) << RTC_TR_MNU_Pos);
    RTC->TR = tr;

    protect();
    return true;
}

unsigned char Rtc::getSec(void)
{
    return ((RTC->TR & RTC_TR_ST_Msk) >> RTC_TR_ST_Pos) * 10 + ((RTC->TR & RTC_TR_SU_Msk) >> RTC_TR_SU_Pos);
}

bool Rtc::setSec(unsigned char sec)
{
    unsigned long tr = RTC->TR;
    unsigned long long endTime = time::getRunningMsec() + 1000;

    unprotect();
    while (!(RTC->ISR & RTC_ISR_INITF_Msk))
    {
        thread::yield();
        if (time::getRunningMsec() >= endTime)
            return false;
    }

    tr &= ~(RTC_TR_ST_Msk | RTC_TR_SU_Msk);
    tr |= ((sec / 10 % 10) << RTC_TR_ST_Pos) | ((sec % 10) << RTC_TR_SU_Pos);
    RTC->TR = tr;

    protect();
    return true;
}

unsigned short Rtc::getSubsec(void)
{
    unsigned long prer = RTC->PRER & 0x7fff;
    unsigned long sub = (prer - RTC->SSR) * 100;
    sub /= prer;
    return (unsigned short)sub;
}

void Rtc::protect(void)
{
    RTC->ISR &= ~RTC_ISR_INIT_Msk;
    while (~RTC->ISR & RTC_ISR_RSF_Msk)
        thread::yield();
    RTC->WPR = 0X00;
    PWR->CR &= ~PWR_CR_DBP_Msk;
}

void Rtc::unprotect(void)
{
    PWR->CR |= PWR_CR_DBP_Msk;
    RTC->WPR = 0xca;
    RTC->WPR = 0x53;
    RTC->ISR |= RTC_ISR_INIT_Msk;
}
*/
}

#endif