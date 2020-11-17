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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.09.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_ADC_ST_TYPE_A_DEFINE__H_
#define YSS_DRV_ADC_ST_TYPE_A_DEFINE__H_

#if	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

namespace define
{
namespace adc
{
	namespace lpfLv
	{
		enum
		{
			LV0 = 0,
			LV1 = 1,
			LV2 = 2,
			LV3 = 3,
			LV4 = 4,
			LV5 = 5,
			LV6 = 6,
			LV7 = 7,
			LV8 = 8,
			LV9 = 9,
			LV10 = 10,
			LV11 = 11,
			LV12 = 12,
			LV13 = 13,
			LV14 = 14,
			LV15 = 15,
			LV16 = 16,
			LV17 = 17,
			LV18 = 18,
			LV19 = 19,
			LV20 = 20
		};
	}

	namespace bit
	{
		enum
		{
			BIT12 = 19,
			BIT13 = 18,
			BIT14 = 17,
			BIT15 = 16,
			BIT16 = 15,
		};
	}
}
}

#endif

#endif
