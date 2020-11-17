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

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <yss/malloc.h>
#include <yss/yss.h>
#include <config.h>
#include <drv/peripherals.h>
#include <drv/ltdc/drv_st_ltdc_type_A_register.h>

#if defined(LTDC_ENABLE) && defined(LTDC)

static void setClockEn(bool en)
{
	clock.peripheral.setLtdcEn(en);
} 

drv::Ltdc ltdc(LTDC, setClockEn, 0);

namespace drv
{
	Ltdc::Ltdc(LTDC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en))  :  Drv(clockFunc, nvicFunc)
	{
		
	}

	bool Ltdc::init(config::ltdc::Config *config)
	{
		unsigned short vsyncWidth = config->vsyncWidth;
		unsigned short vbp = config->vbp;
		unsigned short height = config->height;
		unsigned short vfp = config->vfp;
		unsigned short hsyncWidth = config->hsyncWidth;
		unsigned short hbp = config->hbp;
		unsigned short width = config->width;
		unsigned short hfp = config->hfp;
		unsigned char pixelFormat = config->pixelFormat;

		mConfig = config;

		if(vsyncWidth > 0)
			setLtdcHsw(vsyncWidth - 1);
		else
			setLtdcHsw(0);

		if(hsyncWidth > 0)
			setLtdcVsh(hsyncWidth - 1);
		else
			setLtdcVsh(0);

		setLtdcAhbp(hsyncWidth + hbp - 1);
		setLtdcAvbp(vsyncWidth + vbp - 1);
		setLtdcAaw(hsyncWidth + hbp + width - 1);
		setLtdcAah(vsyncWidth + vbp + height - 1);
		setLtdcTotalw(hsyncWidth + hbp + width + hfp - 1);
		setLtdcTotalh(vsyncWidth + vbp + height + vfp - 1);

		setLtdcHspol(false);
		setLtdcVspol(false);
		setLtdcDepol(false);
		setLtdcPcpol(false);

		setLtdcBcRed(0);
		setLtdcBcGreen(0);
		setLtdcBcBlue(0);

		unsigned short pitch;
		switch(pixelFormat)
		{
		case define::ltdc::format::RGB565 :
			pitch = 2;
		case define::ltdc::format::RGB888 :
			pitch = 3;
			break;
		}

		pitch *= width;

		setLtdcLayerWhpcr(LTDC_Layer1, hsyncWidth + hbp, hsyncWidth + hbp + width - 1);
		setLtdcLayerWvpcr(LTDC_Layer1, vsyncWidth + vbp, vsyncWidth + vbp + height - 1);
		setLtdcLayerPixelFormat(LTDC_Layer1, pixelFormat);
		setLtdcLayerDccr(LTDC_Layer1, 0, 0, 0, 0);
		setLtdcLayerConstAlpha(LTDC_Layer1, 0xff);
		setLtdcLayerBfcr(LTDC_Layer1, 4, 5);
		setLtdcLayerCfblr(LTDC_Layer1, pitch, pitch+3);
		setLtdcLayerFrameBufferLineNumber(LTDC_Layer1, height);
		setLtdcImediateReload();

		setLtdcLayerEn(LTDC_Layer1, true);
		setLtdcImediateReload();

		setLtdcDitherEn(true);
		setLtdcEnable(true);
		return true;
	}

	void Ltdc::setFrameBuffer(void *frame)
	{
		setLtdcLayerFrameBuffer(LTDC_Layer1, (unsigned long)frame);
		setLtdcImediateReload();
	}

	void Ltdc::setFrameBuffer(FrameBuffer &obj)
	{
		Size size = obj.getSize();
		unsigned long frame = (unsigned long)obj.getFrameBuffer();

		if(mConfig->width == size.width && mConfig->height == size.height)
		{
			setLtdcLayerFrameBuffer(LTDC_Layer1, (unsigned long)frame);
			setLtdcImediateReload();
		}
	}

	void Ltdc::setFrameBuffer(FrameBuffer *obj)
	{
		setFrameBuffer(*obj);
	}

	Size Ltdc::getLcdSize(void)
	{
		return Size{mConfig->width, mConfig->height};
	}
}

#endif
#endif
