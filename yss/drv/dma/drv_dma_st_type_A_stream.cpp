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

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <yss/thread.h>
#include <util/time.h>
#include <drv/peripherals.h>
#include <drv/dma/drv_st_dma_type_A_register.h>

namespace drv
{
	Stream::Stream(DMA_Stream_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
	{
		mPeri = peri;
		mCompleteFlag = false;
		mErrorFlag = false;
	}

	void Stream::init(void)
	{
		setDmaStreamFifoEn(mPeri, false);
		setDmaStreamFth(mPeri, 0);
	}

	bool Stream::send(sac::Comm *obj, void *src, unsigned long size, unsigned long timeout)
	{
		unsigned long long endTime;
        unsigned int addr = (unsigned int)src;

		mMutex.lock();
		mCompleteFlag = false;
		mErrorFlag = false;

		sac::DmaInfo *info = obj->getDmaInfo();

		mPeri->PAR = (unsigned long)info->txDr;

        if(size > 0xF000)
        {
			mAddr = addr;
			mPeri->M0AR = addr;
			mPeri->M1AR = mAddr ;
			mPeri->NDTR = 0xF000;
            mRemainSize = size - 0xF000;
			mPeri->CR = (info->txChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
		}
        else
        {
			mPeri->M0AR = addr;
			mPeri->NDTR = size;
            mRemainSize = 0;
			mPeri->CR = (info->txChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
        }

		endTime = time::getRunningMsec() + timeout;
		while(!mCompleteFlag && !mErrorFlag)
		{
			if(endTime <= time::getRunningMsec())
			{
				mPeri->CR &= ~DMA_SxCR_EN_Msk;
				mMutex.unlock();
				return false;
			}
			thread::switchContext();
		}

		mMutex.unlock();

		if(mErrorFlag)
			return false;
		else
			return true;
	}

	void Stream::pendRx(sac::Comm *obj, void *des, unsigned long size)
	{
		mMutex.lock();
		mCompleteFlag = false;
		mErrorFlag = false;

		sac::DmaInfo *info = obj->getDmaInfo();

		mPeri->PAR = (unsigned long)info->txDr;

        if(size > 0xF000)
        {
			mAddr = (unsigned int)des;
			mPeri->M0AR = (unsigned int)des;
			mPeri->M1AR = mAddr ;
			mPeri->NDTR = 0xF000;
            mRemainSize = size - 0xF000;
			mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
		}
        else
        {
			mPeri->M0AR = (unsigned int)des;
			mPeri->NDTR = size;
            mRemainSize = 0;
			mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
        }
	}

	void Stream::stop(void)
	{
		setDmaStreamEn(mPeri, false);
		mMutex.unlock();
	}

	bool Stream::receive(sac::Comm *obj, void *des, unsigned long size, unsigned long timeout)
	{
		unsigned long long endTime;

		mMutex.lock();
		mCompleteFlag = false;
		mErrorFlag = false;

		sac::DmaInfo *info = obj->getDmaInfo();

		mPeri->PAR = (unsigned int)info->rxDr;

        if(size > 0xF000)
        {
			mAddr = (unsigned int)des;
			mPeri->M0AR = (unsigned int)des;
			mPeri->M1AR = mAddr ;
			mPeri->NDTR = 0xF000;
            mRemainSize = size - 0xF000;
			mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
		}
        else
        {
			mPeri->M0AR = (unsigned int)des;
			mPeri->NDTR = size;
            mRemainSize = 0;
			mPeri->CR = (info->rxChannel << DMA_SxCR_CHSEL_Pos) | (info->priority << DMA_SxCR_PL_Pos) | (DMA_SxCR_MINC_Msk | (define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | DMA_SxCR_TCIE_Msk | DMA_SxCR_TEIE_Msk | DMA_SxCR_EN_Msk);
        }

		endTime = time::getRunningMsec() + timeout;
		while(!mCompleteFlag && !mErrorFlag)
		{
			if(endTime <= time::getRunningMsec())
			{
				setDmaStreamEn(mPeri, false);
				mMutex.unlock();
				return false;
			}
			thread::switchContext();
		}

		mMutex.unlock();

		if(mErrorFlag)
			return false;
		else
			return true;
	}

	void Stream::setComplete(void)
	{
		mCompleteFlag = true;
	}

	void Stream::setError(void)
	{
		mErrorFlag = true;
	}
}

#endif
