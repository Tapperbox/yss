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

#include <__cross_studio_io.h>
#include <yss/yss.h>

#define SECTOR 6

unsigned int gSrc[1024 / 4];

int main(void)
{
	const unsigned int *data = (const unsigned int *)flash.getAddress(SECTOR);

	yss::init();

	for (int i = 0; i < 1024 / 4; i++)
	{
		gSrc[i] = i;
	}

	debug_printf("Sector address printing!!");
	for (int i = 0; i < 8; i++)
	{
		debug_printf("Sector[%02d] = 0x%08x\n", i, flash.getAddress(i));
	}

	debug_printf("\n\nSector %d infomation printing!!\n", SECTOR);
	for (int i = 0; i < 1024; i += 4)
	{
		debug_printf("[%04d] = 0x%08X  ", i, data[i / 4]);
		if ((i + 4) % (4 * 4) == 0)
			debug_printf("\n");
	}

	debug_printf("\n\n Erase sector %d!!\n", SECTOR);
	flash.erase(SECTOR);

	debug_printf("\n\nSector %d infomation printing!!\n", SECTOR);
	for (int i = 0; i < 1024; i += 4)
	{
		debug_printf("[%04d] = 0x%08X  ", i, data[i / 4]);
		if ((i + 4) % (4 * 4) == 0)
			debug_printf("\n");
	}

	debug_printf("\n\nProgram sector %d!!\n", SECTOR);
	flash.program(SECTOR, gSrc, 1024 * 4);

	debug_printf("\n\nSector %d infomation printing!!\n", SECTOR);
	for (int i = 0; i < 1024; i += 4)
	{
		debug_printf("[%04d] = 0x%08X  ", i, data[i / 4]);
		if ((i + 4) % (4 * 4) == 0)
			debug_printf("\n");
	}

	while (1)
	{
		thread::yield();
	}
	return 0;
}

