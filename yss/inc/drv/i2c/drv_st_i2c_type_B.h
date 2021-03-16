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

#ifndef YSS_DRV_I2C_ST_TYPE_B__H_
#define YSS_DRV_I2C_ST_TYPE_B__H_

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                               \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                               \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                      \
    defined(STM32F107xC) ||                                                                      \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                               \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                               \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                               \
    defined(STM32F429xx) || defined(STM32F439xx)

#include "drv_st_i2c_type_B_define.h"
#include <yss/mcu.h>
#include <config.h>
#include <drv/Drv.h>
#include <sac/Comm.h>
#include <drv/drv_Dma.h>

namespace drv
{
class I2c : public sac::Comm, public Drv
{
    I2C_TypeDef *mPeri;
    Stream *mTxStream;
    Stream *mRxStream;
    unsigned int (*mGetClockFrequency)(void);

  public:
    I2c(I2C_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChanne, unsigned int (*getClockFrequencyFunc)(void), unsigned short priority);
    bool init(unsigned char speed);
    bool send(unsigned char addr, void *src, unsigned int size, unsigned int timeout);
    bool receive(unsigned char addr, void *des, unsigned int size, unsigned int timeout);
    void stop(void);
};
}

#endif

#endif