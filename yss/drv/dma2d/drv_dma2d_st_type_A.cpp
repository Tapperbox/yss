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

#include <drv/peripherals.h>

#if	defined(DMA2D) && USE_GUI

#include <drv/dma2d/drv_st_dma2d_type_A_register.h>
#include <__cross_studio_io.h>

const unsigned char yssSysFont[1000] = {0,};

static void setClockEn(bool en)
{
	clock.peripheral.setDma2d(en);
} 

static void setIntEn(bool en)
{
//	nvic.setDma2dEn(en);
}

drv::Dma2d dma2d(DMA2D, setClockEn, setIntEn);

namespace drv
{
	unsigned short gDma2dThreadNum;

	Dma2d::Dma2d(DMA2D_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) :  Drv(clockFunc, nvicFunc)
	{
		mFontInfo.size = 0;
		mFontInfo.yPos = 0;
		mFontInfo.pointer = 0;
		mFontInfo.base = 0;
	}

	void Dma2d::init(void)
	{
//		unsigned long *buf;
//		buf = (unsigned long*)&yssSysFont[1];
//		mFontInfo.size = (FontSize*)&yssSysFont[*buf];
//		buf = (unsigned long*)&yssSysFont[5];
//		mFontInfo.yPos = (signed char*)&yssSysFont[*buf];
//		buf = (unsigned long*)&yssSysFont[9];
//		mFontInfo.pointer = (unsigned long*)&yssSysFont[*buf];
//		buf = (unsigned long*)&yssSysFont[13];
//		mFontInfo.base = (unsigned char*)&yssSysFont[*buf];

//		setDma2dTcie(true);
	}

	void Dma2d::draw(Object &des, Object &src)
	{
		draw(des, src, src.getPos());
	}

	void Dma2d::drawArea(Object &des, Pos areaPos, Size areaSize, Object &src)
	{
		drawArea(des, areaPos, areaSize, src, src.getPos());
	}

extern "C"
{
	void DMA2D_IRQHandler(void)
	{
		if(getDma2dTcif())
		{
//			clrDma2dTcif();
//			dma2d.unlockThread();
		}
	}
}
}

#endif
