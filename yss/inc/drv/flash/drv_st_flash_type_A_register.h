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

#ifndef	YSS_DRV_FLASH_ST_TYPE_A_REG__H_
#define	YSS_DRV_FLASH_ST_TYPE_A_REG__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx) || \
	defined(STM32F103xG)

#include <yss/reg.h>

#define	setFlashLatency(x)			setRegField(FLASH->ACR,	0xFUL, x, 0)
#define	setFlashPrefetchEn(x)		setRegBit(FLASH->ACR, x, 8)
#define	setFlashArtEn(x)			setRegBit(FLASH->ACR, x, 9)

#define	setFlashKey(x)				FLASH->KEYR	= x

#define	getFlashBusy()				getRegBit(FLASH->SR, 16)

#define	setFlashProgramming(x)		setRegBit(FLASH->CR, x,	0)
#define	setFlashSectorErase(x)		setRegBit(FLASH->CR, x,	1)
#define	setFlashSectorNumber(x)		setRegField(FLASH->CR, 0xf,	x, 3)
#define	setFlashProgramSize(x)		setRegField(FLASH->CR, 0x3,	x, 8)
#define	setFlashEraseStart()		setRegBit(FLASH->CR, 1,	16)
#define	setFlashLock()				setRegBit(FLASH->CR, 1,	31)
#define	getFlashLock()				getRegBit(FLASH->CR, 31)

#endif

#endif