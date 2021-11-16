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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK_ST_TYPE_C__H_
#define YSS_DRV_CLOCK_ST_TYPE_C__H_

#include <yss/mcu.h>

#if defined(STM32F4)

#include "drv_clock_peripherals.h"
#include "drv_st_clock_type_C_define.h"
#include "drv_st_clock_type_C_ec.h"

namespace drv
{
class Mainpll
{
  public:
	bool enable(unsigned char src, unsigned long vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
	unsigned int getFreq(void);
};

class Saipll
{
  public:
	bool enable(unsigned long vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
	unsigned int getLcdFreq(void);
	unsigned int getSaiFreq(void);
};

class Clock
{
  public:
	bool enableHse(unsigned char hseMhz);
	bool enableLsi(bool en = true);
	bool enableLse(bool en = true);
	bool setUsbClkSrc(unsigned char src);
	bool setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc);
	void setLatency(unsigned long freq, unsigned char vcc);
	unsigned long getSysClkFreq(void);
	unsigned long getApb1ClkFreq(void);
	unsigned long getApb2ClkFreq(void);
	unsigned long getTimerApb1ClkFreq(void);
	unsigned long getTimerApb2ClkFreq(void);
	Mainpll pll;
	Saipll saipll;
	Peripheral peripheral;
};
}

#endif

#endif