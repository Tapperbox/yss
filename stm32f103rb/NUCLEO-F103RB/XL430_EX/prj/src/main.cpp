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
//  주담당자 : 아이구 (mymy49@nate.com) 2019.12.22 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <external/crc16.h>
#include <string.h>
#include <util/Period.h>
#include <yss/yss.h>

#include <mod/dynamixel/XL430.h>
#include <protocol/Dynamixel_V2.h>

DynamixelV2 gDynamixel(uart2);
mod::dynamixel::XL430 gXL430;

// 125 mS 마다 LED를 깜빡이는 쓰레드
void thread_blinkLed(void)
{
	Period period(125000); // 125 ms

	while (1)
	{
		period.wait();
		gXL430.setLed(true);

		period.wait();
		gXL430.setLed(false);
	}
}

// 1초마다 모터를 이동시키는 쓰레드
void thread_moveMotor(void)
{
	Period period(1000000); // 1000 ms

	while (1)
	{
		period.wait();
		gXL430.setGoalPosition(500);

		period.wait();
		gXL430.setGoalPosition(3000);
	}
}

int main(void)
{
	unsigned char motorCount;
	yss::init();
	unsigned char data[32], id;
	signed int presentPosition;

	using namespace define::gpio;

	//UART Init 9600 baudrate, 수신 링버퍼 크기는 512 바이트
	gpioA.setAsAltFunc(2, altfunc::PA2_USART2_TX);

	uart2.setClockEn(true);
	uart2.initOneWire(57600, 512);
	uart2.setIntEn(true);

	if (gDynamixel.init())
	{
		debug_printf("Init Ok!!\n");
		motorCount = gDynamixel.getCount();
		debug_printf("Number of Motor = %d\n", motorCount);
		for (int i = 0; i < motorCount; i++)
		{
			debug_printf("\n## Motor %d Information ##\n", i);
			debug_printf("ID[%d] = %d\n", i, gDynamixel.getId(i));
			debug_printf("Model number[%d] = 0x%04x\n", i, gDynamixel.getModelNumber(i));
			debug_printf("Firmware Version[%d] = %d\n", i, gDynamixel.getFirmwareVersion(i));
		}

		id = gDynamixel.getId(0);
		gXL430.init(gDynamixel, id);
		gXL430.setTorqueEnable(true);
		thread::add(thread_blinkLed, 512);
		thread::add(thread_moveMotor, 512);
	}
	else
	{
		debug_printf("Init Failed!!\n");
	}

	debug_printf("\n");

	while (1)
	{
		// 모터의 현재 위치를 디버그 모니터에 출력
		if(gXL430.getPresentPosition(presentPosition))
			debug_printf("present position = %d\r", presentPosition);
		else
		{
			debug_printf("read failed!!\n");
			thread::delay(1000);
		}
		thread::yield();
	}
	return 0;
}