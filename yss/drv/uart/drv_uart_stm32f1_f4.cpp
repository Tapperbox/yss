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

#include <drv/peripheral.h>

#if defined(STM32F1) || defined(STM32F4)

#include <drv/Uart.h>
#include <drv/uart/register_uart_stm32f1_f4.h>

namespace drv
{
Uart::Uart(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mPeri = config.peri;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
}

error Uart::init(unsigned int baud, unsigned int receiveBufferSize)
{
	void *buf = new unsigned char[receiveBufferSize];
	if (buf == 0)
		return Error::MALLOC_FAILED;
	
	return init(baud, buf, receiveBufferSize);
}

error Uart::init(unsigned int baud, void *receiveBuffer, unsigned int receiveBufferSize)
{
	unsigned int man, fra, buf;
	unsigned int clk = Drv::getClockFrequency() >> 4;

	mRcvBuf = (unsigned char*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;

	setUsartEn(mPeri, false);

	setUsartOver8(mPeri, false);
	setUsartBrr(mPeri, man, fra);

	setUsartTxEn(mPeri, true);
	setUsartRxEn(mPeri, true);
	setUsartRxneiEn(mPeri, true);
	setUsartEn(mPeri, true);

	return Error::NONE;
}

error Uart::send(void *src, unsigned int size, unsigned int timeout)
{
	bool result;

	if(mTxDma == 0)
		return false;

	mTxDma->lock();

	mPeri->CR3 |= USART_CR3_DMAT_Msk;		// TX DMA 활성화
	mPeri->SR = ~USART_SR_TC_Msk;

	if(mOneWireModeFlag)
		mPeri->CR1 &= ~USART_CR1_RE_Msk;	// RX 비활성화
	
	result = mTxDma->send(mTxDmaInfo, src, size, timeout);
	if(result)
	{
		__ISB();
		while (!(mPeri->SR & USART_SR_TC_Msk))
			thread::yield();
	}

	if(mOneWireModeFlag)
		mPeri->CR1 |= USART_CR1_RE_Msk;		// RX 활성화

	mPeri->CR3 &= ~USART_CR3_DMAT_Msk;		// TX DMA 비활성화

	mTxDma->unlock();

	return result;
}

void Uart::send(char data)
{
	if(mOneWireModeFlag)
		mPeri->CR1 &= ~USART_CR1_RE_Msk;	// RX 비활성화

	mPeri->SR = ~USART_SR_TC_Msk;
	mPeri->DR = data;
	while (~mPeri->SR & USART_SR_TC_Msk)
		thread::yield();

	if(mOneWireModeFlag)
		mPeri->CR1 |= USART_CR1_RE_Msk;		// RX 활성화
}

void Uart::isr(void)
{
	unsigned int sr = mPeri->SR;

	push(mPeri->DR);

	if (sr & (1 << 3))
	{
		flush();
	}
}
}
#endif

