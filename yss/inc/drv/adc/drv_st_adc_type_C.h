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

#ifndef YSS_DRV_ADC_ST_TYPE_A__H_
#define YSS_DRV_ADC_ST_TYPE_A__H_

#if	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)

#include "drv_st_adc_type_C_define.h"
#include <drv/Drv.h>

namespace drv
{
	class Adc : public Drv
	{
		ADC_TypeDef *mPeri;
		signed int mResult[18];
		unsigned char mIndex;
        unsigned char mLpfLv[18];
        unsigned char mChannel[18];
        unsigned char mBit[18];
        unsigned char mNumOfCh;

	public :
		Adc(ADC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
		bool init(void);
        void isr(void);
		void add(unsigned char pin, unsigned char lpfLv = define::adc::lpfLv::LV0, unsigned char bit = define::adc::bit::BIT12);
		unsigned short get(unsigned char pin);
	};
}

#if defined(ADC1_ENABLE) && defined(ADC1)
extern drv::Adc adc1;
#endif

#if defined(ADC2_ENABLE) && defined(ADC2)
extern drv::Adc adc2;
#endif

#endif

#endif
