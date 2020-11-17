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

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>

Rgb888::Rgb888(void)
{
	mDotSize = 3;
	mBrushColor.byte[0] = 0x0;
	mBrushColor.byte[1] = 0x0;
	mBrushColor.byte[2] = 0x0;
	mFontColorReg = 0xff000000;
	mBgColor.byte[0] = 0xff;
	mBgColor.byte[1] = 0xff;
	mBgColor.byte[2] = 0xff;
	mColorMode =  define::ltdc::format::RGB888;	
}

void Rgb888::drawDot(signed short x, signed short y)
{
	unsigned char *des = (unsigned char*)mFrameBuffer, *src = (unsigned char*)mBrushColor.byte;

    des += (FrameBuffer::mSize.width * y + x) * 3;
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;
}

void Rgb888::drawDot(signed short x, signed short y, unsigned short color)
{
}

void Rgb888::drawDot(signed short x, signed short y, unsigned int color)
{
	unsigned char *des = (unsigned char*)mFrameBuffer, *src = (unsigned char*)&color;

    des += (FrameBuffer::mSize.width * y + x) * 3;
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;

}

void Rgb888::drawFontDot(signed short x, signed short y, unsigned char color)
{

}

void Rgb888::eraseDot(Pos pos)
{
	unsigned char *des = (unsigned char*)mFrameBuffer, *src = (unsigned char*)mBgColor.byte;

    des += FrameBuffer::mSize.width * pos.y + pos.x * 3;
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;
}

void Rgb888::clear(void)
{
	dma2d.fill(*this, mBgColor);
}

void Rgb888::clearRectangle(Pos pos, Size size)
{
	dma2d.fillRectangle(*this, pos, size, mBgColor);
}

void Rgb888::setColor(RGB888_struct color)
{
	mBrushColor.color = color;
}

void Rgb888::setColor(RGB888_union color)
{
	mBrushColor = color;
}

void Rgb888::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mBrushColor.color.red = red;
	mBrushColor.color.green = green;
	mBrushColor.color.blue = blue;
}

void Rgb888::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mFontColorReg = alpha << 24 | red << 16 | green << 8 | blue;
}

void Rgb888::setColor(unsigned char *arry)
{

}

void Rgb888::setColor(unsigned short color)
{

}

void Rgb888::setBgColor(RGB888_struct color)
{
	mBrushColor.color = color;
}

void Rgb888::setBgColor(RGB888_union color)
{
	mBgColor = color;
}

void Rgb888::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.red = red;
	mBgColor.color.green = green;
	mBgColor.color.blue = blue;
}

void Rgb888::setBgColor(unsigned char *arry)
{

}

void Rgb888::setBgColor(unsigned short color)
{

}

void Rgb888::setColorLevel(unsigned char level)
{

}

void Rgb888::drawBmp565(Pos pos, const Bmp565 *image)
{

}

unsigned char Rgb888::drawChar(Pos pos, unsigned int utf8)
{
	if(mFrameBuffer)
		return dma2d.drawChar(*this, &mFont, utf8, pos, mFontColorReg, (unsigned char)(mFontColorReg >> 24));
	else
		return 0;
}

/*
Rgb888::Rgb888(void)
{
	mDotSize = 3;
	mBrushColor.data[0] = 0x0;
	mBrushColor.data[1] = 0x0;
	mBrushColor.data[2] = 0x0;
	mBgColor.data[0] = 0xff;
	mBgColor.data[1] = 0xff;
	mBgColor.data[2] = 0xff;
	mColorMode = define::ltdc::format::RGB888;
}

void Rgb888::drawDot(Pos pos)
{
	unsigned char *buf = (unsigned char*)mFrameBuffer;

	if(mFrameBuffer)
	{
		if(pos.y < FrameBuffer::mSize.height && pos.x < FrameBuffer::mSize.width)
		{
			buf = &buf[pos.y * FrameBuffer::mSize.width * 3 + pos.x * 3];
			buf[0] = mBrushColor.data[0];
			buf[1] = mBrushColor.data[1];
			buf[2] = mBrushColor.data[2];
		}
	}
}

void Rgb888::drawDotQuick(Pos pos)
{
	unsigned char *buf = (unsigned char*)mFrameBuffer;
	buf = &buf[pos.y * FrameBuffer::mSize.width * 3 + pos.x * 3];
	buf[0] = mBrushColor.data[0];
	buf[1] = mBrushColor.data[1];
	buf[2] = mBrushColor.data[2];
}

void Rgb888::setColor(RGB888_struct color)
{
	mBrushColor.color = color;
}

void Rgb888::setBgColor(RGB888_struct color)
{
	mBgColor.color = color;
}

void Rgb888::setColor(RGB888_union color)
{
	mBrushColor = color;
}

void Rgb888::setBgColor(RGB888_union color)
{
	mBgColor = color;
}

void Rgb888::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mBrushColor.color.red = red;
	mBrushColor.color.green = green;
	mBrushColor.color.blue = blue;
}

void Rgb888::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.red = red;
	mBgColor.color.green = green;
	mBgColor.color.blue = blue;
}

void Rgb888::fill(void)
{
	dma2d.fill(*this, mBrushColor);
}

void Rgb888::clear(void)
{
	dma2d.fill(*this, mBgColor);
}

void Rgb888::clearRectangle(Pos pos, Size size)
{
	dma2d.fillRectangle(*this, pos, size, mBgColor);
}

void Rgb888::setSize(Size size)
{
	FrameBuffer::setSize(size);
//	Brush::setSize(size);
}

signed char Rgb888::drawChar(Pos pos, char* ch)
{
	if(mFrameBuffer)
	{
//		dma2d::setFontColor(mBrushColor.color.red, mBrushColor.color.green, mBrushColor.color.blue);
//		return dma2d::drawChar(*this, ch, pos);
		return 0;
	}

	return 0;
}

signed char Rgb888::drawChar(Pos pos, char ch)
{
	if(mFrameBuffer)
	{
//		dma2d::setFontColor(mBrushColor.color.red, mBrushColor.color.green, mBrushColor.color.blue);
//		return dma2d::drawChar(*this, ch, pos);
		return 0;
	}

	return 0;
}

void Rgb888::fillRect(Pos p1, Pos p2)
{
//	dma2d::fillRectangle(*this, p1, p2, mBrushColor);
}

void Rgb888::fillRect(Pos pos, Size size)
{
//	dma2d::fillRectangle(*this, pos, size, mBrushColor);
}
*/
/*
void Rgb888::draw(Rgb888 obj, Pos pos)
{
//	dma2d::draw(*this, obj, pos);
}
*/
#endif