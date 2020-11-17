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

#include <__cross_studio_io.h>
#include <drv/peripherals.h>
#include <mod/ctouch/FT5336.h>
#include <yss/event.h>

#if defined(I2C1)
#define ADDR		0x70
namespace mod
{
namespace ctouch
{
	static void trigger_handler(void *peri);

	bool FT5336::init(drv::I2c &peri, config::gpio::Set &isr)
	{
		unsigned char data;

		mPeri = &peri;
        mIsr = isr;
		thread::delay(100);

		if(getByte(0xa8) != 0x51)
			return false;

		mTriggerId = trigger::add(trigger_handler, this, 512);

		if(mTriggerId == 0)
			return false;

		return exti.add(*mIsr.port, mIsr.pin, define::exti::mode::FALLING, mTriggerId);
	}

	char FT5336::getByte(char addr)
	{
		mPeri->lock();
		mPeri->send(ADDR, (char*)&addr, 1, 100);
		mPeri->receive(ADDR, (char*)&addr, 1, 100);
		mPeri->stop();
		mPeri->unlock();

		return addr;
	}

	bool FT5336::getMultiByte(char addr, char *des, unsigned char size)
	{
		bool rt = false;

		mPeri->lock();
		if(mPeri->send(ADDR, (char*)&addr, 1, 100))
		{
			rt = mPeri->receive(ADDR, des, size, 100);
		}
		mPeri->stop();
		mPeri->unlock();

		return rt;
	}

	static void trigger_handler(void *var)
	{
		FT5336 *ft5336 = (FT5336*)var;
		static bool penDown = false;
		unsigned char evt, id;
		unsigned short x, y, buf;
		char data[4];

		ft5336->getMultiByte(0x03, data, 4);
		evt = data[0];
		x = (evt & 0x0f) << 8;
		evt >>= 6;
		x |= data[1];
		id = data[2];
		y = (id & 0x0f) << 8;
		id >>= 6;
		y |= data[3];

//		if(gPort.swap)
//		{
			buf = x;
			x = y;
			y = buf;
//		}

		if((evt == 0x00) && (penDown == false))
		{
			penDown = true;
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
			event::add(x, y, event::PUSH);
			event::trigger();
#endif
		}
		else if((evt == 0x02) && penDown == true)
		{
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
			event::add(x, y, event::DRAG);
			event::trigger();
#endif
		}
		else if((evt == 0x01) && penDown == true)
		{
			penDown = false;
#if USE_GUI && YSS_L_HEAP_USE && USE_EVENT
			event::add(x, y, event::UP);
			event::trigger();
#endif
		}
	}

/*




*/
}
}

#endif