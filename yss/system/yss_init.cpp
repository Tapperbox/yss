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

#include <yss/mcu.h>
#include <config.h>
#include <internal/time.h>
#include <internal/systick.h>
#include <internal/scheduler.h>
#include <internal/system.h>
#include <internal/malloc.h>
#include <drv/peripherals.h>
#include <yss/event.h>
#include <yss/malloc.h>

#define	YSS_L_HEAP_TOTAL_CLUSTER_SIZE		(YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)

namespace yss
{
	void initLheap(void)
	{
#if YSS_L_HEAP_USE == true
		unsigned long *sdram = (unsigned long*)YSS_SDRAM_ADDR;
		
		while((unsigned long)sdram < YSS_L_HEAP_BASE_ADDR)
			*sdram++ = 0;
#endif
	}

    void initCheap(void)
    {
#if YSS_C_HEAP_USE == true && defined(CCMDATARAM_BASE)
		unsigned long *ccm = (unsigned long*)CCMDATARAM_BASE;
		
		while((unsigned long)ccm < YSS_C_HEAP_BASE_ADDR)
			*ccm++ = 0;
#endif
	}

	void init(void)
	{
#if defined(ERROR_MCU_NOT_ABLE) == false
		Mutex mutex;
		mutex.init();

#if defined(__CORE_CM7_H_GENERIC) || defined(__CORE_CM4_H_GENERIC)
		// Lazy Stacking 비활성화
		FPU->FPCCR = 0;
#endif
		// 문맥전환 활성화
		NVIC_SetPriority(PendSV_IRQn, 15);
		initSystemTime();
		initScheduler();
		SysTick_Config(THREAD_GIVEN_CLOCK);

#if defined(DMA1)
		// DMA 활성화
		dma.setClockEn(true);
		dma.init();
		dma.setIntEn(true);
#endif


#if defined(DMA2D) && USE_GUI == true
#endif

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE && USE_EVENT
		event::init();
#endif

#if defined(SYSCFG)
		syscfg.setClockEn(true);
#endif

#if defined(EXTI)
		exti.setClockEn(true);
		exti.setIntEn(true);
#endif
#endif
	}
}

