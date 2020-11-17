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

#ifndef YSS_GUI_RGB565__H_
#define YSS_GUI_RGB565__H_

#include "FrameBuffer.h"

class Rgb565 : public FrameBuffer
{
	RGB565_union mBrushColor, mBgColor;
	unsigned int mFontColorReg;
public:
	Rgb565(void);
	unsigned char drawChar(Pos pos, unsigned int utf8);
	void setColorLevel(unsigned char level);
	void drawBmp565(Pos pos, const Bmp565 *image);
	void drawBmp565(Pos pos, const Bmp565 &image);
	void drawDot(signed short x, signed short y);
	void drawDot(signed short x, signed short y, unsigned short color);
	void drawDot(signed short x, signed short y, unsigned int color);
	void drawFontDot(signed short x, signed short y, unsigned char color);

	void eraseDot(Pos pos);
	void clear(void);
	void clearRectangle(Pos pos, Size size);
	void setColor(RGB565_struct);
	void setColor(RGB565_union);
	void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setColor(unsigned char *arry);
	void setColor(unsigned short color);
	void setBgColor(RGB565_struct);
	void setBgColor(RGB565_union);
	void setBgColor(unsigned char red, unsigned char green, unsigned char blue);
	void setBgColor(unsigned char *arry);
	void setBgColor(unsigned short color);
};

#endif