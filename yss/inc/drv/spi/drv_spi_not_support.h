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
//	Copyright 2019.	yss Embedded Operating System all right reserved.
//  
//  이전 주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 2020.01.04
//  주담당자 : 두드림 (vivastudy7@gmail.com) 2020.01.04 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef	YSS_DRV_SPI_NOT_SUPPORT__H_
#define	YSS_DRV_SPI_NOT_SUPPORT__H_

#include "drv_spi_common.h"

namespace drv
{
	class Spi : public sac::Comm, public Drv
	{
		Stream *mTxStream;
		Stream *mRxStream;
		config::spi::Config *mLastConfig;
		unsigned long (*mGetClockFreq)(void);

	public :
		Spi(void);
		bool init(void);
		bool setConfig(config::spi::Config &config);
		bool send(void *src, unsigned long size, unsigned long timeout);
        unsigned char exchange(unsigned char data);
		bool exchange(void *des, unsigned long size, unsigned long timeout);
		void send(char data);
		void send(unsigned char data);
		void enable(bool en);
	};
}

#if defined(SPI1_ENABLE) && defined(SPI1)
extern drv::Spi spi1;
#endif

#if defined(SPI2_ENABLE) && defined(SPI2)
extern drv::Spi spi2;
#endif

#if defined(SPI3_ENABLE) && defined(SPI3)
extern drv::Spi spi3;
#endif

#endif
