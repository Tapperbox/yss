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

#ifndef YSS_DRV_CLOCK_ST_TYPE_D_DEFINE__H_
#define YSS_DRV_CLOCK_ST_TYPE_D_DEFINE__H_

#if	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

namespace define
{
namespace clock
{
	namespace voltageScale
	{
		enum
        {
			RANGE1_NORMAL,
			RANGE1_BOOST,
			RANGE2
		};
    }

	namespace pll
	{
		namespace src
		{
			enum
			{
				HSI = 2,
				HSE = 3
			};
		}

		namespace pdiv
		{
			enum
			{
				DIV2 = 2,
				DIV3 = 3,
				DIV4 = 4,
				DIV5 = 5,
				DIV6 = 6,
				DIV7 = 7,
				DIV8 = 8,
				DIV9 = 9,
				DIV10 = 10,
				DIV11 = 11,
				DIV12 = 12,
				DIV13 = 13,
				DIV14 = 14,
				DIV15 = 15,
				DIV16 = 16,
				DIV17 = 17,
				DIV18 = 18,
				DIV19 = 19,
				DIV20 = 20,
				DIV21 = 21,
				DIV22 = 22,
				DIV23 = 23,
				DIV24 = 24,
				DIV25 = 25,
				DIV26 = 26,
				DIV27 = 27,
				DIV28 = 28,
				DIV29 = 29,
				DIV30 = 30,
				DIV31 = 31,
			};
		}

		namespace qdiv
		{
			enum
			{
				DIV2 = 0,
				DIV4 = 1,
				DIV6 = 2,
				DIV8 = 3,
			};
		}

		namespace rdiv
		{
			enum
			{
				DIV2 = 0,
				DIV4 = 1,
				DIV6 = 2,
				DIV8 = 3,
			};
		}
	}

	namespace saipll
	{
		namespace qdiv
		{
			enum
			{
				DIV2 = 2,
				DIV3 = 3,
				DIV4 = 4,
				DIV5 = 5,
				DIV6 = 6,
				DIV7 = 7,
				DIV8 = 8,
				DIV9 = 9,
				DIV10 = 10,
				DIV11 = 11,
				DIV12 = 12,
				DIV13 = 13,
				DIV14 = 14,
				DIV15 = 15
			};
		}

		namespace rdiv
		{
			enum
			{
				DIV2 = 2,
				DIV3 = 3,
				DIV4 = 4,
				DIV5 = 5,
				DIV6 = 6,
				DIV7 = 7
			};
		}
	}

	namespace usbclk
	{
		namespace src
		{
			enum
			{
				MAIN_PLL = 0,
				SAI_PLL = 1,
			};
		}
	}

	namespace sysclk
	{
		namespace src
		{
			enum
			{
				HSI = 1,
				HSE = 2,
				PLL = 3
			};
		}
	}

	namespace divFactor
	{
		namespace ahb
		{
			enum
			{
				NO_DIV = 0,
				DIV2 = 0x8,
				DIV4 = 0x9,
				DIV8 = 0xa,
				DIV16 = 0xb,
				DIV64 = 0xc,
				DIV128 = 0xd,
				DIV256 = 0xe,
				DIV512 = 0xf
			};
		}

		namespace apb
		{
			enum
			{
				NO_DIV = 0,
				DIV2 = 0x4,
				DIV4 = 0x5,
				DIV8 = 0x6,
				DIV16 = 0x7,
			};
		}

	}

	namespace adc
	{
		namespace src
		{
			enum
			{
				NO_CLK = 0,
				PLL = 1,
				SYSCLK = 2
			};
		}
	}

	namespace can
	{
		namespace src
		{
			enum
			{
				HSE = 0,
				PLLQ = 1,
				PCLK1 = 2
			};
		}
	}

	namespace i2c
	{
		namespace src
		{
			enum
			{
				PCLK1 = 0,
				SYSCLK = 1,
				HSI16 = 2
			};
		}
	}

}
}

#endif

#endif
