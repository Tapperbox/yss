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

#ifndef	YSS_DRV_USBD_ST_TYPE_A__H_
#define	YSS_DRV_USBD_ST_TYPE_A__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) || \
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#define YSS_USB_USED

#include "drv_st_usbd_type_A_config.h"
#include "drv_st_usbd_type_A_define.h"

#define MAX_EP_NUM		8

namespace drv
{
	class UsbOutData
	{
		unsigned long mMaxSize, mHead, mTail, mTailAbsent;
		unsigned char *mData;
		bool mActive;
	public:
		UsbOutData(unsigned long maxSize);
		~UsbOutData(void);
		void push(unsigned long *fifo, unsigned short size);
		signed short pop(void);
		signed short popAbsent(void);
		void flush(void);
		void flushAbsent(void);
		unsigned long getRxSize(void);
		unsigned char* getRxBuffer(void);
		bool pop(void *des, unsigned long size, unsigned long timeOut);
		unsigned long getFreeSize(void);
	};

	class Usbd
	{
		unsigned char mPeriId;

		Mutex mMutex[MAX_EP_NUM];
		config::usbd::Config *mConfig;
		UsbOutData *mOutData[MAX_EP_NUM];
		signed long mDeviceSetupHandlerId;
		unsigned long *mTxBuffer[MAX_EP_NUM];
		unsigned long mTxSize[MAX_EP_NUM];
		bool mTxCompleteFlag[MAX_EP_NUM];
		unsigned char mSetupRxBuffer[8];
		unsigned short mSetupRxSize;

	public:
		Usbd(config::usbd::Config &config);

		bool init(void (*handler)(config::usbd::SetupRequest *request));
//		bool init(void (*handler)(void));
		void mallocOutEndpoint(unsigned char epNum, unsigned long size);
		void write(unsigned char epNum, unsigned char *data, unsigned long size, unsigned long timeout);
		void stall(unsigned char epNum = 0);
		void setAddress(unsigned short addr);
		void activeOutEndpoint(unsigned char epNum, unsigned char epType, unsigned short size);
		void activeInEndpoint(unsigned char epNum, unsigned char epType, unsigned short size);
		void setOutEpDataReceive(unsigned char epNum);
		bool resetCore(void);
		bool flushTxFifo(unsigned char num);
		bool flushRxFifo(void);
		bool initFifo(void);
		void setInterruptEn(bool en);
		void disableEndPoint(unsigned char num);
		void isr(void);
		void writeSetup(unsigned char *data, unsigned long size, unsigned long timeout);
		UsbOutData* getOutEndpointData(unsigned char epNum);
	};
/*
	class Usbd
	{

		signed long mCheckRecevingBufferFullId;
		bool mRxBufferFullFlag[MAX_EP_NUM];
		bool mRxBufferLockFlag[MAX_EP_NUM];
		unsigned char mStatus;

	public :
		Usbd(config::usbd::Config &config);
	};
*/
}

#if defined(USB_OTG_FS)
extern drv::Usbd usbdFs;
#endif

#if defined(USB_OTG_HS)
extern drv::Usbd usbdHs;
#endif

#endif

#endif
