////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

#include <drv/peripheral.h>
#include <drv/Exti.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/exti_stm32_gd32f1.h>

Exti::Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

bool Exti::add(Gpio &gpio, uint8_t pin, uint8_t mode, void (*func)(void))
{
	volatile uint32_t* peri = (volatile uint32_t*)EXTI;

	if (pin > 15)
		return false;

	mTriggerFlag[pin] = false;
	mIsr[pin] = func;
	gpio.setExti(pin);

	using namespace define::exti;
	setBitData(peri[EXTI_REG::RTSR], (mode::RISING & mode) == mode::RISING, pin);
	setBitData(peri[EXTI_REG::FTSR], (mode::FALLING & mode) == mode::FALLING, pin);
	setBitData(peri[EXTI_REG::IMR], true, pin);

	return true;
}

bool Exti::add(Gpio &gpio, uint8_t pin, uint8_t mode, int32_t  trigger)
{
	volatile uint32_t* peri = (volatile uint32_t*)EXTI;

	if (pin > 15)
		return false;

	mTriggerFlag[pin] = true;
	mTriggerNum[pin] = trigger;
	gpio.setExti(pin);
	
	using namespace define::exti;
	setBitData(peri[EXTI_REG::RTSR], (mode::RISING & mode) == mode::RISING, pin);
	setBitData(peri[EXTI_REG::FTSR], (mode::FALLING & mode) == mode::FALLING, pin);
	setBitData(peri[EXTI_REG::IMR], true, pin);

	return true;
}

void Exti::isr(int32_t  num)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	if (mTriggerFlag[num])
		trigger::run(mTriggerNum[num]);
	else if(mIsr[num])
		mIsr[num]();
#else
	if (mIsr[num])
		mIsr[num]();
#endif
}

#endif

