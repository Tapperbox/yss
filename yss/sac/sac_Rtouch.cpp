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

#include <config.h>

#include <sac/Rtouch.h>
#include <yss/event.h>

#if USE_EVENT == true


namespace  sac
{
	Rtouch::Rtouch(void)
    {
		mP1X = mP1Y = mP2X = mP2Y = mWidth = mHeight = 0;
        mInitFlag = false;
    }

	void Rtouch::setCalibration(signed int p1X, signed int p1y, signed int p2x, signed int p2y)
	{
		mP1X = p1X;
        mP1Y = p1y;
        mP2X = p2x;
        mP2Y = p2y;
	}

	void Rtouch::getCalibration(signed int *p1X, signed int *p1y, signed int *p2x, signed int *p2y)
	{
		
	}

	void Rtouch::setSize(signed int width, signed height)
    {
		mWidth = width - 40;
        mHeight = height - 40;
    }

	Pos Rtouch::calculate(unsigned short x, unsigned short y)
	{
		signed int tX = x, tY = y;
		Pos pos;

		tX -= mP1X;
		tX *= mWidth;
		tX /= mP2X - mP1X;
        tX += 20;
		if(tX < 0)
			tX = 0;
		else if(tX > mWidth + 40)
			tX = mWidth + 40;
		pos.x = (unsigned short)tX;

		tY -= mP1Y;
		tY *= mHeight;
		tY /= mP2Y - mP1Y;
        tY += 20;
		if(tY < 0)
			tY = 0;
		else if(tY > mHeight + 40)
			tY = mHeight + 40;
		pos.y = (unsigned short)tY;

		return pos;
	}

	void Rtouch::set(unsigned short x, unsigned short y, unsigned char event)
    {
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
		event::add(calculate(x, y), event);
#endif
    }

    void Rtouch::trigger(void)
    {
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
		event::trigger();
#endif
    }
}

#else
namespace  sac
{
	Rtouch::Rtouch(void)
    {
    }
}
#endif
