/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_ERROR__H_
#define YSS_ERROR__H_

#include <stdint.h>

// 프로젝트에서 사용하는 모든 에러를 정의합니다.
typedef enum
{
	ERROR_NONE = 0,

// 범용
	BUSY,
	OVERSIZE,
	MALLOC_FAILED,
	OVERFLOW,
	BUFFER_SIZE,
	INDEX_OVER,
	NOT_READY,
	TX_UNDERRUN,
	RX_OVERRUN,
	DMA_ERROR,
	TIMEOUT,
	UNSUPPORTED_MODE,
	WRONG_CONFIG,
	WRONG_INDEX,
	NOT_INITIALIZED,
	OUT_OF_RANGE,
	UNKNOWN,
	NOT_CONNECTED,
	FAILED_THREAD_ADDING,
	WRONG_SIZE,
	WRONG_CLOCK_FREQUENCY,
	IT_ALREADY_HAVE,
	NOT_HAVE_SPECIFICATON,
	NACK,
	FAIL,
	CHECK_SUM,
	NOT_SUPPORTED_FORMAT,
	NOT_SUPPORTED_YET,
	ALREADY_OPENED,
	ALREADY_CLOSED,
	WRONG_RESPONSE,
	UNKNOWN_DEVICE,
	DMA_ALLOCATION_FAILED,
	OUT_OF_CHANNEL,
	
// FAT 관련
	SECTOR_READ,
	SIGNATURE,
	PARTITION_TYPE,
	NO_BOOT_SECTOR,
	NO_DATA,
	NO_FREE_DATA,
	NO_FILE,
	NOT_EXIST_NAME,
	WRONG_FORMAT,
	WRONG_FILE_NAME,
	WRONG_DIRECTORY_NAME,
	WRONG_DIRECTORY_PATH,
	FILE_NOT_OPENED,
	END_OF_FILE,

// SD메모리 관련
	BAD_SECTOR,
	NOT_DIRECTORY,
	SAME_FILE_NAME_EXIST,
	NO_RESPONSE_CMD,
	CMD_TIMEOUT,
	DATA_TIMEOUT,
	CMD_CRC_FAIL,
	DATA_CRC_FAIL,
	SDCARD_NOT_ABLE,

// CLOCK 관련
	SYSCLK_SRC_IS_PLL,
	HSE_NOT_READY,
	PLL_NOT_READY,
	CLK_SRC_NOT_ABLE,
	SYSCLK_WAS_NOT_CHANGED,

// CAN 통신 관련
	SLEEP_ACK_INTERRUPT,
	WAKEUP_INTERRUPT,
	ERROR_INTERRUP,

// GPIO 관련
	OUT_OF_PIN_INDEX_RANGE,
	THIS_PIN_DO_NOT_HAVE_GPIO_OUTPUT,

// DYNAMIXEL 관련
	INSTRUCTION_ERROR,
	CRC_ERROR,
	DATA_RANGE_ERROR,
	DATA_LENGTH_ERROR,
	DATA_LIMIT_ERROR,
	ACCESS_ERROR,

// Flash Memory 관련
	LOCK_MODE,
	BROWN_OUT_DETECTED,
	FAILED_FLASH_PROGRAM,
	ISPFF_FLAG,

// USB 관련
	UNSUPPORTED_EP,
	UNSUPPORTED_EP_BUF,
}error_t;

#endif