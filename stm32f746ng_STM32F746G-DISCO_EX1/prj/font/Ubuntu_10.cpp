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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.06.07 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include "Ubuntu_10.h"

unsigned char Ubuntu_10[4866] = 
{
	0x59, 0x53, 0x53, 0x20, 0x46, 0x4f, 0x4e, 0x54, 0x00, 0x01, 		// 10
	0xa5, 0x05, 0x00, 0x00, 0x04, 0x09, 0x02, 0xb7, 0x05, 0x00, 		// 20
	0x00, 0x06, 0x04, 0x01, 0xc3, 0x05, 0x00, 0x00, 0x0a, 0x09, 		// 30
	0x02, 0xf0, 0x05, 0x00, 0x00, 0x08, 0x0c, 0x01, 0x20, 0x06, 		// 40
	0x00, 0x00, 0x0c, 0x09, 0x02, 0x56, 0x06, 0x00, 0x00, 0x0a, 		// 50
	0x09, 0x02, 0x83, 0x06, 0x00, 0x00, 0x04, 0x04, 0x01, 0x8b, 		// 60
	0x06, 0x00, 0x00, 0x04, 0x0e, 0x00, 0xa7, 0x06, 0x00, 0x00, 		// 70
	0x04, 0x0e, 0x00, 0xc3, 0x06, 0x00, 0x00, 0x06, 0x06, 0x01, 		// 80
	0xd5, 0x06, 0x00, 0x00, 0x08, 0x07, 0x03, 0xf1, 0x06, 0x00, 		// 90
	0x00, 0x04, 0x04, 0x09, 0xf9, 0x06, 0x00, 0x00, 0x04, 0x02, 		// 100
	0x06, 0xfd, 0x06, 0x00, 0x00, 0x04, 0x02, 0x09, 0x01, 0x07, 		// 110
	0x00, 0x00, 0x08, 0x0d, 0x00, 0x35, 0x07, 0x00, 0x00, 0x08, 		// 120
	0x09, 0x02, 0x59, 0x07, 0x00, 0x00, 0x04, 0x09, 0x02, 0x6b, 		// 130
	0x07, 0x00, 0x00, 0x08, 0x09, 0x02, 0x8f, 0x07, 0x00, 0x00, 		// 140
	0x08, 0x09, 0x02, 0xb3, 0x07, 0x00, 0x00, 0x08, 0x09, 0x02, 		// 150
	0xd7, 0x07, 0x00, 0x00, 0x08, 0x09, 0x02, 0xfb, 0x07, 0x00, 		// 160
	0x00, 0x08, 0x09, 0x02, 0x1f, 0x08, 0x00, 0x00, 0x08, 0x09, 		// 170
	0x02, 0x43, 0x08, 0x00, 0x00, 0x08, 0x09, 0x02, 0x67, 0x08, 		// 180
	0x00, 0x00, 0x08, 0x09, 0x02, 0x8b, 0x08, 0x00, 0x00, 0x04, 		// 190
	0x07, 0x04, 0x99, 0x08, 0x00, 0x00, 0x04, 0x09, 0x04, 0xab, 		// 200
	0x08, 0x00, 0x00, 0x08, 0x06, 0x04, 0xc3, 0x08, 0x00, 0x00, 		// 210
	0x08, 0x05, 0x05, 0xd7, 0x08, 0x00, 0x00, 0x08, 0x06, 0x04, 		// 220
	0xef, 0x08, 0x00, 0x00, 0x06, 0x09, 0x02, 0x0a, 0x09, 0x00, 		// 230
	0x00, 0x0c, 0x0b, 0x02, 0x4c, 0x09, 0x00, 0x00, 0x0a, 0x09, 		// 240
	0x02, 0x79, 0x09, 0x00, 0x00, 0x08, 0x09, 0x02, 0x9d, 0x09, 		// 250
	0x00, 0x00, 0x08, 0x09, 0x02, 0xc1, 0x09, 0x00, 0x00, 0x08, 		// 260
	0x09, 0x02, 0xe5, 0x09, 0x00, 0x00, 0x06, 0x09, 0x02, 0x00, 		// 270
	0x0a, 0x00, 0x00, 0x06, 0x09, 0x02, 0x1b, 0x0a, 0x00, 0x00, 		// 280
	0x08, 0x09, 0x02, 0x3f, 0x0a, 0x00, 0x00, 0x08, 0x09, 0x02, 		// 290
	0x63, 0x0a, 0x00, 0x00, 0x02, 0x09, 0x02, 0x6c, 0x0a, 0x00, 		// 300
	0x00, 0x06, 0x09, 0x02, 0x87, 0x0a, 0x00, 0x00, 0x08, 0x09, 		// 310
	0x02, 0xab, 0x0a, 0x00, 0x00, 0x06, 0x09, 0x02, 0xc6, 0x0a, 		// 320
	0x00, 0x00, 0x0c, 0x09, 0x02, 0xfc, 0x0a, 0x00, 0x00, 0x08, 		// 330
	0x09, 0x02, 0x20, 0x0b, 0x00, 0x00, 0x0a, 0x09, 0x02, 0x4d, 		// 340
	0x0b, 0x00, 0x00, 0x08, 0x09, 0x02, 0x71, 0x0b, 0x00, 0x00, 		// 350
	0x0a, 0x0c, 0x02, 0xad, 0x0b, 0x00, 0x00, 0x08, 0x09, 0x02, 		// 360
	0xd1, 0x0b, 0x00, 0x00, 0x08, 0x09, 0x02, 0xf5, 0x0b, 0x00, 		// 370
	0x00, 0x08, 0x09, 0x02, 0x19, 0x0c, 0x00, 0x00, 0x08, 0x09, 		// 380
	0x02, 0x3d, 0x0c, 0x00, 0x00, 0x0a, 0x09, 0x02, 0x6a, 0x0c, 		// 390
	0x00, 0x00, 0x0c, 0x09, 0x02, 0xa0, 0x0c, 0x00, 0x00, 0x08, 		// 400
	0x09, 0x02, 0xc4, 0x0c, 0x00, 0x00, 0x08, 0x09, 0x02, 0xe8, 		// 410
	0x0c, 0x00, 0x00, 0x08, 0x09, 0x02, 0x0c, 0x0d, 0x00, 0x00, 		// 420
	0x04, 0x0d, 0x00, 0x26, 0x0d, 0x00, 0x00, 0x08, 0x0d, 0x00, 		// 430
	0x5a, 0x0d, 0x00, 0x00, 0x04, 0x0d, 0x00, 0x74, 0x0d, 0x00, 		// 440
	0x00, 0x08, 0x05, 0x02, 0x88, 0x0d, 0x00, 0x00, 0x08, 0x02, 		// 450
	0x0c, 0x90, 0x0d, 0x00, 0x00, 0x04, 0x04, 0x00, 0x98, 0x0d, 		// 460
	0x00, 0x00, 0x06, 0x07, 0x04, 0xad, 0x0d, 0x00, 0x00, 0x06, 		// 470
	0x0b, 0x00, 0xce, 0x0d, 0x00, 0x00, 0x06, 0x07, 0x04, 0xe3, 		// 480
	0x0d, 0x00, 0x00, 0x08, 0x0b, 0x00, 0x0f, 0x0e, 0x00, 0x00, 		// 490
	0x08, 0x07, 0x04, 0x2b, 0x0e, 0x00, 0x00, 0x06, 0x0a, 0x01, 		// 500
	0x49, 0x0e, 0x00, 0x00, 0x08, 0x09, 0x04, 0x6d, 0x0e, 0x00, 		// 510
	0x00, 0x06, 0x0b, 0x00, 0x8e, 0x0e, 0x00, 0x00, 0x04, 0x0a, 		// 520
	0x01, 0xa2, 0x0e, 0x00, 0x00, 0x04, 0x0c, 0x01, 0xba, 0x0e, 		// 530
	0x00, 0x00, 0x06, 0x0b, 0x00, 0xdb, 0x0e, 0x00, 0x00, 0x04, 		// 540
	0x0b, 0x00, 0xf1, 0x0e, 0x00, 0x00, 0x0a, 0x07, 0x04, 0x14, 		// 550
	0x0f, 0x00, 0x00, 0x06, 0x07, 0x04, 0x29, 0x0f, 0x00, 0x00, 		// 560
	0x08, 0x07, 0x04, 0x45, 0x0f, 0x00, 0x00, 0x06, 0x09, 0x04, 		// 570
	0x60, 0x0f, 0x00, 0x00, 0x08, 0x09, 0x04, 0x84, 0x0f, 0x00, 		// 580
	0x00, 0x04, 0x07, 0x04, 0x92, 0x0f, 0x00, 0x00, 0x06, 0x07, 		// 590
	0x04, 0xa7, 0x0f, 0x00, 0x00, 0x06, 0x0a, 0x01, 0xc5, 0x0f, 		// 600
	0x00, 0x00, 0x08, 0x07, 0x04, 0xe1, 0x0f, 0x00, 0x00, 0x08, 		// 610
	0x07, 0x04, 0xfd, 0x0f, 0x00, 0x00, 0x0a, 0x07, 0x04, 0x20, 		// 620
	0x10, 0x00, 0x00, 0x08, 0x07, 0x04, 0x3c, 0x10, 0x00, 0x00, 		// 630
	0x08, 0x09, 0x04, 0x60, 0x10, 0x00, 0x00, 0x06, 0x07, 0x04, 		// 640
	0x75, 0x10, 0x00, 0x00, 0x06, 0x0d, 0x00, 0x9c, 0x10, 0x00, 		// 650
	0x00, 0x02, 0x0d, 0x00, 0xa9, 0x10, 0x00, 0x00, 0x04, 0x0d, 		// 660
	0x00, 0xc3, 0x10, 0x00, 0x00, 0x08, 0x03, 0x06, 0x00, 0x00, 		// 670
	0x00, 0x00, 0x00, 0x00, 0xb1, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 680
	0x00, 0xb1, 0x08, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 		// 690
	0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcf, 		// 700
	0x10, 0x00, 0x00, 0xdb, 0x10, 0x00, 0x00, 0xdf, 0x10, 0x00, 		// 710
	0x00, 0xdf, 0x10, 0x00, 0x00, 0xdf, 0x10, 0x00, 0x00, 0xe3, 		// 720
	0x10, 0x00, 0x00, 0xeb, 0x10, 0x00, 0x00, 0xeb, 0x10, 0x00, 		// 730
	0x00, 0xeb, 0x10, 0x00, 0x00, 0xc6, 0x11, 0x00, 0x00, 0x15, 		// 740
	0x12, 0x00, 0x00, 0x15, 0x12, 0x00, 0x00, 0x15, 0x12, 0x00, 		// 750
	0x00, 0x64, 0x12, 0x00, 0x00, 0x02, 0x13, 0x00, 0x00, 0x02, 		// 760
	0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 770
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 780
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 790
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 800
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 810
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 820
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 830
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 840
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 850
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 860
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 870
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 880
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 890
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 900
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 910
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 920
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 930
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 940
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 950
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 960
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 970
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 980
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 990
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1000
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1010
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1020
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1030
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1040
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1050
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1060
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1070
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1080
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1090
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1100
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1110
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1120
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1130
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1140
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1150
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1160
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1170
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1180
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1190
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1200
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1210
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1220
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1230
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1240
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1250
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1260
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1270
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1280
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1290
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1300
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1310
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1320
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1330
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1340
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1350
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1360
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1370
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1380
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1390
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1400
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1410
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1420
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1430
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 1440
	0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x07, 0xd0, 0x07, 0xd0, 		// 1450
	0x07, 0xc0, 0x06, 0xc0, 0x05, 0xa0, 0x04, 0x20, 0x00, 0x90, 		// 1460
	0x05, 0xd0, 0x07, 0xf0, 0xb3, 0x08, 0xf0, 0xb2, 0x07, 0xe0, 		// 1470
	0x91, 0x05, 0x40, 0x30, 0x01, 0x00, 0xf0, 0x00, 0x3d, 0x00, 		// 1480
	0x00, 0xd4, 0x10, 0x0f, 0x00, 0xf5, 0xff, 0xff, 0xff, 0x00, 		// 1490
	0x00, 0x7a, 0x70, 0x0a, 0x00, 0x00, 0x4c, 0x90, 0x07, 0x00, 		// 1500
	0x00, 0x2f, 0xc0, 0x05, 0x00, 0xf5, 0xff, 0xff, 0xff, 0x00, 		// 1510
	0x50, 0x0c, 0xf1, 0x00, 0x00, 0x80, 0x08, 0xb5, 0x00, 0x00, 		// 1520
	0x00, 0xd0, 0x03, 0x00, 0x10, 0xfa, 0xbe, 0x00, 0xc0, 0x2a, 		// 1530
	0x52, 0x00, 0xf0, 0x05, 0x00, 0x00, 0xc0, 0x5e, 0x00, 0x00, 		// 1540
	0x10, 0xfa, 0x5e, 0x00, 0x00, 0x10, 0xf9, 0x03, 0x00, 0x00, 		// 1550
	0xd0, 0x07, 0x50, 0x01, 0xf3, 0x05, 0xb0, 0xff, 0x8e, 0x00, 		// 1560
	0x00, 0xd0, 0x03, 0x00, 0x00, 0x60, 0x01, 0x00, 0x90, 0xde, 		// 1570
	0x03, 0xb0, 0x06, 0x00, 0xc3, 0x60, 0x0b, 0xd4, 0x00, 0x00, 		// 1580
	0xd3, 0x60, 0x0b, 0x4d, 0x00, 0x00, 0x90, 0xce, 0x62, 0x0b, 		// 1590
	0x00, 0x00, 0x00, 0x00, 0xe1, 0xa3, 0x9e, 0x00, 0x00, 0x00, 		// 1600
	0x99, 0xa6, 0xc0, 0x05, 0x00, 0x20, 0x1e, 0x69, 0x80, 0x07, 		// 1610
	0x00, 0xb0, 0x07, 0xa6, 0xb0, 0x05, 0x00, 0xe4, 0x00, 0xb0, 		// 1620
	0xae, 0x00, 0x00, 0xe8, 0x5e, 0x00, 0x00, 0x40, 0x1e, 0xf3, 		// 1630
	0x00, 0x00, 0x50, 0x0c, 0xf2, 0x00, 0x00, 0x00, 0x8e, 0x5d, 		// 1640
	0x00, 0x00, 0x30, 0xfd, 0x09, 0x40, 0x00, 0xf1, 0x24, 0x6e, 		// 1650
	0xc4, 0x00, 0xd5, 0x00, 0xe2, 0x5e, 0x00, 0xf2, 0x03, 0xb1, 		// 1660
	0x6f, 0x00, 0x50, 0xed, 0x7e, 0xe3, 0x03, 0xf0, 0x03, 0xf0, 		// 1670
	0x02, 0xe0, 0x01, 0x40, 0x00, 0x00, 0x01, 0x40, 0x0e, 0xd0, 		// 1680
	0x06, 0xe4, 0x00, 0x99, 0x00, 0x5d, 0x00, 0x4e, 0x00, 0x4e, 		// 1690
	0x00, 0x5d, 0x00, 0x8a, 0x00, 0xd5, 0x00, 0xe0, 0x04, 0x50, 		// 1700
	0x0d, 0x00, 0x03, 0x01, 0x00, 0x8a, 0x00, 0xf2, 0x01, 0xa0, 		// 1710
	0x08, 0x50, 0x0d, 0x20, 0x1f, 0x00, 0x2f, 0x00, 0x2f, 0x10, 		// 1720
	0x1f, 0x50, 0x0e, 0x90, 0x09, 0xf1, 0x02, 0x9a, 0x00, 0x02, 		// 1730
	0x00, 0x00, 0x10, 0x00, 0x00, 0xa6, 0x00, 0x93, 0x96, 0x77, 		// 1740
	0x72, 0xec, 0x48, 0x40, 0x9d, 0x07, 0x70, 0x15, 0x0a, 0x00, 		// 1750
	0x60, 0x01, 0x00, 0x00, 0xd0, 0x03, 0x00, 0x00, 0xd0, 0x03, 		// 1760
	0x00, 0xe4, 0xfe, 0xef, 0x09, 0x10, 0xd1, 0x14, 0x01, 0x00, 		// 1770
	0xd0, 0x03, 0x00, 0x00, 0xd0, 0x03, 0x00, 0xf0, 0x05, 0xf0, 		// 1780
	0x02, 0xe3, 0x00, 0x42, 0x00, 0xfa, 0x8f, 0x21, 0x12, 0xb0, 		// 1790
	0x03, 0xe1, 0x04, 0x00, 0x00, 0x70, 0x01, 0x00, 0x00, 0xe3, 		// 1800
	0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 		// 1810
	0x40, 0x0e, 0x00, 0x00, 0xa0, 0x08, 0x00, 0x00, 0xf0, 0x03, 		// 1820
	0x00, 0x00, 0xd5, 0x00, 0x00, 0x00, 0x8b, 0x00, 0x00, 0x10, 		// 1830
	0x2f, 0x00, 0x00, 0x60, 0x0c, 0x00, 0x00, 0xc0, 0x07, 0x00, 		// 1840
	0x00, 0xf1, 0x01, 0x00, 0x00, 0x10, 0xfb, 0x4d, 0x00, 0xa0, 		// 1850
	0x2b, 0xf7, 0x01, 0xf1, 0x03, 0xd0, 0x06, 0xf3, 0x00, 0xa0, 		// 1860
	0x09, 0xf4, 0x00, 0x90, 0x0a, 0xf3, 0x00, 0xa0, 0x09, 0xf1, 		// 1870
	0x03, 0xd0, 0x06, 0xa0, 0x2b, 0xf7, 0x01, 0x10, 0xfb, 0x4d, 		// 1880
	0x00, 0x00, 0xd9, 0xc4, 0xde, 0x66, 0xd6, 0x00, 0xd6, 0x00, 		// 1890
	0xd6, 0x00, 0xd6, 0x00, 0xd6, 0x00, 0xd6, 0x00, 0xd6, 0x70, 		// 1900
	0xfd, 0x3c, 0x00, 0xa1, 0x24, 0xea, 0x00, 0x00, 0x00, 0xf4, 		// 1910
	0x00, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x50, 0x2e, 0x00, 0x00, 		// 1920
	0xe5, 0x03, 0x00, 0x30, 0x3f, 0x00, 0x00, 0xc0, 0x07, 0x00, 		// 1930
	0x00, 0xf0, 0xff, 0xff, 0x06, 0x90, 0xfe, 0x3c, 0x00, 0x40, 		// 1940
	0x12, 0xe9, 0x00, 0x00, 0x10, 0xb9, 0x00, 0x00, 0xfa, 0x2e, 		// 1950
	0x00, 0x00, 0x10, 0xe9, 0x00, 0x00, 0x00, 0xf0, 0x04, 0x00, 		// 1960
	0x00, 0xf0, 0x04, 0x50, 0x22, 0xe9, 0x00, 0xc2, 0xef, 0x2b, 		// 1970
	0x00, 0x00, 0x00, 0xbc, 0x00, 0x00, 0xa0, 0xbe, 0x00, 0x00, 		// 1980
	0xc6, 0xb7, 0x00, 0x10, 0x2e, 0xb7, 0x00, 0xa0, 0x07, 0xb7, 		// 1990
	0x00, 0xe2, 0x00, 0xb7, 0x00, 0xf7, 0xff, 0xff, 0x0c, 0x00, 		// 2000
	0x00, 0xb7, 0x00, 0x00, 0x00, 0xb7, 0x00, 0x40, 0xff, 0xff, 		// 2010
	0x01, 0x50, 0x0c, 0x00, 0x00, 0x60, 0x0a, 0x00, 0x00, 0x70, 		// 2020
	0x7d, 0x04, 0x00, 0x30, 0x86, 0xbe, 0x00, 0x00, 0x00, 0xf1, 		// 2030
	0x03, 0x00, 0x00, 0xe0, 0x05, 0x50, 0x22, 0xf8, 0x01, 0xc0, 		// 2040
	0xff, 0x3c, 0x00, 0x00, 0x70, 0xfc, 0x00, 0x00, 0xac, 0x13, 		// 2050
	0x00, 0x80, 0x0a, 0x00, 0x00, 0xe0, 0xfd, 0x7e, 0x00, 0xf1, 		// 2060
	0x04, 0xe3, 0x05, 0xf2, 0x02, 0x90, 0x0a, 0xf0, 0x04, 0xa0, 		// 2070
	0x09, 0xa0, 0x1c, 0xf4, 0x03, 0x10, 0xea, 0x6e, 0x00, 0xf3, 		// 2080
	0xff, 0xff, 0x08, 0x10, 0x11, 0xf3, 0x03, 0x00, 0x00, 0x8c, 		// 2090
	0x00, 0x00, 0x40, 0x1e, 0x00, 0x00, 0xb0, 0x08, 0x00, 0x00, 		// 2100
	0xf1, 0x02, 0x00, 0x00, 0xd6, 0x00, 0x00, 0x00, 0xa9, 0x00, 		// 2110
	0x00, 0x00, 0x7c, 0x00, 0x00, 0x20, 0xfb, 0x6d, 0x00, 0xd0, 		// 2120
	0x18, 0xf4, 0x03, 0xf0, 0x03, 0xd0, 0x05, 0xb0, 0x1b, 0xe5, 		// 2130
	0x01, 0x20, 0xef, 0x7f, 0x00, 0xd0, 0x06, 0xf4, 0x05, 0xf3, 		// 2140
	0x00, 0xa0, 0x09, 0xf1, 0x16, 0xe3, 0x06, 0x40, 0xfd, 0x8e, 		// 2150
	0x00, 0x30, 0xfc, 0x3d, 0x00, 0xf1, 0x16, 0xe6, 0x00, 0xf4, 		// 2160
	0x00, 0xd0, 0x05, 0xf2, 0x05, 0xc1, 0x07, 0x50, 0xfd, 0xfd, 		// 2170
	0x07, 0x00, 0x00, 0xf1, 0x05, 0x00, 0x00, 0xe9, 0x00, 0x00, 		// 2180
	0xa3, 0x5f, 0x00, 0xc0, 0xae, 0x03, 0x00, 0xe1, 0x04, 0xa0, 		// 2190
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x03, 0xe1, 		// 2200
	0x04, 0xe1, 0x04, 0xa0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 2210
	0x00, 0xb0, 0x03, 0xf0, 0x03, 0xf2, 0x00, 0x84, 0x00, 0x00, 		// 2220
	0x00, 0x81, 0x06, 0x00, 0xa3, 0xaf, 0x03, 0xc2, 0x7d, 0x01, 		// 2230
	0x00, 0xe3, 0x5c, 0x00, 0x00, 0x00, 0xc5, 0x7e, 0x01, 0x00, 		// 2240
	0x00, 0xa3, 0x07, 0xe4, 0xee, 0xee, 0x09, 0x10, 0x11, 0x11, 		// 2250
	0x01, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xee, 0xee, 0x09, 0x10, 		// 2260
	0x11, 0x11, 0x01, 0xa1, 0x03, 0x00, 0x00, 0x70, 0xce, 0x06, 		// 2270
	0x00, 0x00, 0x50, 0xeb, 0x06, 0x00, 0x20, 0xf9, 0x07, 0x50, 		// 2280
	0xec, 0x18, 0x00, 0xc2, 0x06, 0x00, 0x00, 0xd6, 0xdf, 0x03, 		// 2290
	0x23, 0xa1, 0x0c, 0x00, 0x70, 0x0c, 0x00, 0xe2, 0x04, 0x10, 		// 2300
	0x4e, 0x00, 0x50, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x40, 0x0a, 		// 2310
	0x00, 0x70, 0x0d, 0x00, 0x00, 0x40, 0xeb, 0xdf, 0x19, 0x00, 		// 2320
	0x00, 0xd9, 0x15, 0x20, 0xe9, 0x03, 0x50, 0x1d, 0xc4, 0xef, 		// 2330
	0x66, 0x0e, 0xd0, 0x15, 0x6f, 0xa0, 0x09, 0x5c, 0xf0, 0x61, 		// 2340
	0x0d, 0xa0, 0x09, 0x79, 0xf1, 0x60, 0x0c, 0xa0, 0x09, 0x6b, 		// 2350
	0xf0, 0x21, 0x4f, 0xa0, 0x2a, 0x2f, 0xd0, 0x05, 0xf6, 0xdf, 		// 2360
	0xff, 0x07, 0x60, 0x1e, 0x00, 0x01, 0x00, 0x00, 0x00, 0xe9, 		// 2370
	0x16, 0x10, 0x01, 0x00, 0x00, 0x40, 0xeb, 0xef, 0x06, 0x00, 		// 2380
	0x00, 0x70, 0x2f, 0x00, 0x00, 0x00, 0xe0, 0x9e, 0x00, 0x00, 		// 2390
	0x00, 0xe6, 0xf5, 0x00, 0x00, 0x00, 0x8c, 0xe0, 0x06, 0x00, 		// 2400
	0x20, 0x2f, 0x90, 0x0d, 0x00, 0x90, 0x0c, 0x30, 0x3f, 0x00, 		// 2410
	0xe0, 0xef, 0xee, 0x9f, 0x00, 0xf5, 0x12, 0x11, 0xf8, 0x00, 		// 2420
	0xab, 0x00, 0x00, 0xf1, 0x05, 0xfc, 0xef, 0x3b, 0x00, 0x6d, 		// 2430
	0x21, 0xfa, 0x01, 0x6d, 0x00, 0xf1, 0x03, 0x6d, 0x00, 0xf7, 		// 2440
	0x01, 0xfd, 0xfe, 0x7f, 0x00, 0x6d, 0x21, 0xe5, 0x06, 0x6d, 		// 2450
	0x00, 0xa0, 0x0a, 0x6d, 0x21, 0xf6, 0x06, 0xfc, 0xff, 0x7d, 		// 2460
	0x00, 0x00, 0xb3, 0xff, 0x5c, 0x40, 0xaf, 0x24, 0x45, 0xd0, 		// 2470
	0x0a, 0x00, 0x00, 0xf2, 0x04, 0x00, 0x00, 0xf3, 0x02, 0x00, 		// 2480
	0x00, 0xf2, 0x03, 0x00, 0x00, 0xe0, 0x0a, 0x00, 0x00, 0x50, 		// 2490
	0x9f, 0x23, 0x44, 0x00, 0xb3, 0xff, 0x6d, 0xfc, 0xef, 0x4b, 		// 2500
	0x00, 0x7d, 0x31, 0xf7, 0x07, 0x6d, 0x00, 0x60, 0x2f, 0x6d, 		// 2510
	0x00, 0x00, 0x6f, 0x6d, 0x00, 0x00, 0x8d, 0x6d, 0x00, 0x00, 		// 2520
	0x6f, 0x6d, 0x00, 0x60, 0x2f, 0x7d, 0x31, 0xf8, 0x07, 0xfc, 		// 2530
	0xef, 0x4b, 0x00, 0xfd, 0xff, 0xaf, 0x7d, 0x11, 0x01, 0x6d, 		// 2540
	0x00, 0x00, 0x6d, 0x00, 0x00, 0xfd, 0xff, 0x2f, 0x7d, 0x22, 		// 2550
	0x02, 0x6d, 0x00, 0x00, 0x7d, 0x11, 0x11, 0xfd, 0xff, 0xff, 		// 2560
	0xfd, 0xff, 0x9f, 0x7d, 0x11, 0x01, 0x6d, 0x00, 0x00, 0x6d, 		// 2570
	0x00, 0x00, 0xfd, 0xff, 0x1f, 0x7d, 0x22, 0x02, 0x6d, 0x00, 		// 2580
	0x00, 0x6d, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0xb3, 0xff, 		// 2590
	0x7d, 0x30, 0xaf, 0x24, 0x55, 0xd0, 0x0a, 0x00, 0x00, 0xf2, 		// 2600
	0x04, 0x00, 0x00, 0xf3, 0x02, 0x00, 0x62, 0xf2, 0x03, 0x00, 		// 2610
	0xe6, 0xd0, 0x09, 0x00, 0xe6, 0x40, 0x9f, 0x23, 0xe8, 0x00, 		// 2620
	0xb3, 0xff, 0x9e, 0x6d, 0x00, 0x30, 0x1f, 0x6d, 0x00, 0x30, 		// 2630
	0x1f, 0x6d, 0x00, 0x30, 0x1f, 0x6d, 0x00, 0x30, 0x1f, 0xfd, 		// 2640
	0xff, 0xff, 0x1f, 0x7d, 0x22, 0x52, 0x1f, 0x6d, 0x00, 0x30, 		// 2650
	0x1f, 0x6d, 0x00, 0x30, 0x1f, 0x6d, 0x00, 0x30, 0x1f, 0x6d, 		// 2660
	0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x00, 0x00, 		// 2670
	0x7c, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x7c, 		// 2680
	0x00, 0x00, 0x7c, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x6e, 0x45, 		// 2690
	0x72, 0x2f, 0xd7, 0xdf, 0x05, 0x6d, 0x00, 0xf3, 0x05, 0x6d, 		// 2700
	0x30, 0x6e, 0x00, 0x6d, 0xe2, 0x06, 0x00, 0x9d, 0x6e, 0x00, 		// 2710
	0x00, 0xfd, 0x2e, 0x00, 0x00, 0x6d, 0xf9, 0x04, 0x00, 0x6d, 		// 2720
	0x70, 0x3f, 0x00, 0x6d, 0x00, 0xe8, 0x02, 0x6d, 0x00, 0xb0, 		// 2730
	0x0c, 0x6d, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x6d, 0x00, 0x00, 		// 2740
	0x6d, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x6d, 		// 2750
	0x00, 0x00, 0x7d, 0x11, 0x01, 0xfd, 0xff, 0x8f, 0x80, 0x0e, 		// 2760
	0x00, 0x00, 0xd9, 0x00, 0x90, 0x7f, 0x00, 0x20, 0xff, 0x00, 		// 2770
	0xb0, 0xeb, 0x00, 0x90, 0xfb, 0x00, 0xc0, 0xc6, 0x07, 0xf1, 		// 2780
	0xf2, 0x01, 0xd0, 0x45, 0x0e, 0xa8, 0xf0, 0x03, 0xe0, 0x04, 		// 2790
	0x6d, 0x3e, 0xe0, 0x04, 0xf0, 0x03, 0xf6, 0x0b, 0xd0, 0x05, 		// 2800
	0xf0, 0x03, 0xb0, 0x04, 0xd0, 0x06, 0xf1, 0x02, 0x00, 0x00, 		// 2810
	0xc0, 0x07, 0x9d, 0x00, 0x00, 0x5e, 0xfd, 0x06, 0x00, 0x5e, 		// 2820
	0x9d, 0x3f, 0x00, 0x5e, 0x6d, 0xe6, 0x01, 0x5e, 0x6d, 0xa0, 		// 2830
	0x0a, 0x5e, 0x6d, 0x10, 0x5e, 0x5e, 0x6d, 0x00, 0xe4, 0x5e, 		// 2840
	0x6d, 0x00, 0xa0, 0x5f, 0x6d, 0x00, 0x10, 0x5e, 0x00, 0xb3, 		// 2850
	0xff, 0x4c, 0x00, 0x40, 0x9f, 0x33, 0xf8, 0x05, 0xd0, 0x0a, 		// 2860
	0x00, 0x80, 0x0e, 0xf2, 0x03, 0x00, 0x10, 0x4f, 0xf3, 0x02, 		// 2870
	0x00, 0x00, 0x5f, 0xf2, 0x03, 0x00, 0x10, 0x4f, 0xd0, 0x0a, 		// 2880
	0x00, 0x80, 0x0e, 0x30, 0x9f, 0x33, 0xf8, 0x05, 0x00, 0xb3, 		// 2890
	0xff, 0x4c, 0x00, 0xfc, 0xef, 0x4b, 0x00, 0x7d, 0x21, 0xf8, 		// 2900
	0x03, 0x6d, 0x00, 0xe0, 0x07, 0x6d, 0x00, 0xf6, 0x04, 0xfd, 		// 2910
	0xff, 0x6d, 0x00, 0x7d, 0x02, 0x00, 0x00, 0x6d, 0x00, 0x00, 		// 2920
	0x00, 0x6d, 0x00, 0x00, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x00, 		// 2930
	0xb3, 0xff, 0x4c, 0x00, 0x40, 0x9f, 0x33, 0xf8, 0x05, 0xd0, 		// 2940
	0x0a, 0x00, 0x80, 0x0e, 0xf2, 0x03, 0x00, 0x10, 0x4f, 0xf3, 		// 2950
	0x02, 0x00, 0x00, 0x5f, 0xf2, 0x03, 0x00, 0x10, 0x4f, 0xd0, 		// 2960
	0x09, 0x00, 0x70, 0x0e, 0x40, 0x8f, 0x22, 0xf7, 0x06, 0x00, 		// 2970
	0xc3, 0xff, 0x4c, 0x00, 0x00, 0x00, 0xf1, 0x06, 0x00, 0x00, 		// 2980
	0x00, 0x30, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x10, 0x01, 0xfc, 		// 2990
	0xef, 0x2a, 0x00, 0x7d, 0x21, 0xe8, 0x01, 0x6d, 0x00, 0xf0, 		// 3000
	0x05, 0x6d, 0x00, 0xf6, 0x04, 0xfd, 0xfe, 0xbf, 0x00, 0x7d, 		// 3010
	0x81, 0x0d, 0x00, 0x6d, 0x00, 0x7c, 0x00, 0x6d, 0x00, 0xf3, 		// 3020
	0x02, 0x6d, 0x00, 0xa0, 0x0b, 0x50, 0xfd, 0xbe, 0x00, 0xf2, 		// 3030
	0x27, 0x63, 0x00, 0xf4, 0x00, 0x00, 0x00, 0xe1, 0x3b, 0x00, 		// 3040
	0x00, 0x10, 0xf9, 0x4c, 0x00, 0x00, 0x00, 0xf7, 0x03, 0x00, 		// 3050
	0x00, 0xd0, 0x07, 0x63, 0x22, 0xf6, 0x04, 0xc4, 0xff, 0x6d, 		// 3060
	0x00, 0xfc, 0xff, 0xff, 0x2f, 0x11, 0xf1, 0x16, 0x01, 0x00, 		// 3070
	0xf0, 0x05, 0x00, 0x00, 0xf0, 0x05, 0x00, 0x00, 0xf0, 0x05, 		// 3080
	0x00, 0x00, 0xf0, 0x05, 0x00, 0x00, 0xf0, 0x05, 0x00, 0x00, 		// 3090
	0xf0, 0x05, 0x00, 0x00, 0xf0, 0x05, 0x00, 0x5f, 0x00, 0x50, 		// 3100
	0x0e, 0x5f, 0x00, 0x50, 0x0e, 0x5f, 0x00, 0x50, 0x0e, 0x5f, 		// 3110
	0x00, 0x50, 0x0e, 0x5f, 0x00, 0x50, 0x0e, 0x5e, 0x00, 0x60, 		// 3120
	0x0e, 0x8c, 0x00, 0x90, 0x0c, 0xf6, 0x26, 0xf6, 0x05, 0x60, 		// 3130
	0xfe, 0x6d, 0x00, 0xba, 0x00, 0x00, 0xf1, 0x03, 0xf5, 0x01, 		// 3140
	0x00, 0xd7, 0x00, 0xf0, 0x06, 0x00, 0x8c, 0x00, 0x90, 0x0b, 		// 3150
	0x20, 0x2f, 0x00, 0x30, 0x2f, 0x80, 0x0c, 0x00, 0x00, 0x8c, 		// 3160
	0xe0, 0x05, 0x00, 0x00, 0xe6, 0xe5, 0x00, 0x00, 0x00, 0xe0, 		// 3170
	0x8e, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0xc8, 0x00, 		// 3180
	0x00, 0x00, 0x00, 0xaa, 0xf5, 0x00, 0x90, 0x0b, 0x00, 0x7d, 		// 3190
	0xf2, 0x02, 0xe0, 0x1f, 0x00, 0x3f, 0xe0, 0x06, 0xd4, 0x6b, 		// 3200
	0x30, 0x0f, 0xb0, 0x09, 0x79, 0xb6, 0x70, 0x0c, 0x70, 0x0d, 		// 3210
	0x2e, 0xf1, 0xa1, 0x08, 0x20, 0x6f, 0x0c, 0xa0, 0xe7, 0x03, 		// 3220
	0x00, 0xfd, 0x06, 0x40, 0xff, 0x00, 0x00, 0xf9, 0x01, 0x00, 		// 3230
	0xae, 0x00, 0xf3, 0x03, 0x10, 0x6e, 0x80, 0x0d, 0xa0, 0x0b, 		// 3240
	0x00, 0x8d, 0xf5, 0x01, 0x00, 0xf3, 0x6e, 0x00, 0x00, 0xd0, 		// 3250
	0x2f, 0x00, 0x00, 0xd8, 0xca, 0x00, 0x30, 0x3f, 0xe1, 0x07, 		// 3260
	0xc0, 0x08, 0x50, 0x1f, 0xe6, 0x00, 0x00, 0xab, 0xda, 0x00, 		// 3270
	0x00, 0x6e, 0xf1, 0x05, 0x70, 0x0d, 0x80, 0x0d, 0xe1, 0x04, 		// 3280
	0x00, 0x7d, 0xb9, 0x00, 0x00, 0xf4, 0x1f, 0x00, 0x00, 0xc0, 		// 3290
	0x09, 0x00, 0x00, 0xb0, 0x08, 0x00, 0x00, 0xb0, 0x08, 0x00, 		// 3300
	0x00, 0xb0, 0x08, 0x00, 0xf5, 0xff, 0xff, 0x0d, 0x10, 0x11, 		// 3310
	0xf3, 0x07, 0x00, 0x00, 0x9c, 0x00, 0x00, 0x90, 0x0d, 0x00, 		// 3320
	0x00, 0xf4, 0x02, 0x00, 0x10, 0x6e, 0x00, 0x00, 0x90, 0x0c, 		// 3330
	0x00, 0x00, 0xf3, 0x14, 0x11, 0x01, 0xf8, 0xff, 0xff, 0x0f, 		// 3340
	0xfb, 0x2f, 0x6b, 0x00, 0x6b, 0x00, 0x6b, 0x00, 0x6b, 0x00, 		// 3350
	0x6b, 0x00, 0x6b, 0x00, 0x6b, 0x00, 0x6b, 0x00, 0x6b, 0x00, 		// 3360
	0x6b, 0x00, 0x6b, 0x00, 0xfb, 0x2f, 0x71, 0x00, 0x00, 0x00, 		// 3370
	0xe0, 0x04, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x40, 0x0e, 		// 3380
	0x00, 0x00, 0x00, 0x5e, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 		// 3390
	0x00, 0xf3, 0x00, 0x00, 0x00, 0xd0, 0x05, 0x00, 0x00, 0x80, 		// 3400
	0x0b, 0x00, 0x00, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x6c, 0x00, 		// 3410
	0x00, 0x00, 0xc7, 0x00, 0x00, 0x00, 0xf1, 0x02, 0xfd, 0x0f, 		// 3420
	0x10, 0x0f, 0x10, 0x0f, 0x10, 0x0f, 0x10, 0x0f, 0x10, 0x0f, 		// 3430
	0x10, 0x0f, 0x10, 0x0f, 0x10, 0x0f, 0x10, 0x0f, 0x10, 0x0f, 		// 3440
	0x10, 0x0f, 0xfd, 0x0f, 0x00, 0xf2, 0x07, 0x00, 0x00, 0xbb, 		// 3450
	0x1f, 0x00, 0x40, 0x1e, 0xa9, 0x00, 0xd0, 0x06, 0xf1, 0x03, 		// 3460
	0xb2, 0x00, 0x70, 0x06, 0xf0, 0xff, 0xff, 0x7f, 0x10, 0x11, 		// 3470
	0x11, 0x01, 0x00, 0x00, 0xd0, 0x03, 0x40, 0x1d, 0x00, 0x02, 		// 3480
	0x80, 0xff, 0x1b, 0x20, 0x21, 0xac, 0x00, 0x00, 0xd6, 0x80, 		// 3490
	0xfe, 0xde, 0xe4, 0x02, 0xd6, 0xe5, 0x02, 0xd6, 0x90, 0xfe, 		// 3500
	0xae, 0x01, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x4f, 0x00, 0x00, 		// 3510
	0x4f, 0x00, 0x00, 0xcf, 0xee, 0x08, 0x8f, 0x42, 0x7e, 0x4f, 		// 3520
	0x00, 0xd6, 0x4f, 0x00, 0xf4, 0x4f, 0x00, 0xd7, 0x6f, 0x41, 		// 3530
	0x6e, 0xeb, 0xdf, 0x07, 0x10, 0xfa, 0x7f, 0xb0, 0x2b, 0x22, 		// 3540
	0xf2, 0x01, 0x00, 0xf4, 0x00, 0x00, 0xf3, 0x01, 0x00, 0xc0, 		// 3550
	0x3b, 0x21, 0x10, 0xea, 0x9f, 0x00, 0x00, 0x00, 0x01, 0x00, 		// 3560
	0x00, 0x90, 0x0a, 0x00, 0x00, 0x90, 0x0a, 0x00, 0x00, 0x90, 		// 3570
	0x0a, 0x10, 0xfb, 0xdd, 0x0a, 0xc0, 0x2a, 0xc3, 0x0a, 0xf2, 		// 3580
	0x01, 0x90, 0x0a, 0xf4, 0x00, 0x90, 0x0a, 0xf2, 0x01, 0x90, 		// 3590
	0x0a, 0xc0, 0x3c, 0xa1, 0x0a, 0x10, 0xea, 0xef, 0x07, 0x10, 		// 3600
	0xfa, 0x5d, 0x00, 0xc0, 0x1a, 0xf4, 0x02, 0xf3, 0x01, 0xc0, 		// 3610
	0x07, 0xf4, 0xff, 0xff, 0x08, 0xf2, 0x01, 0x00, 0x00, 0xc0, 		// 3620
	0x2a, 0x31, 0x00, 0x10, 0xea, 0xdf, 0x00, 0xc2, 0xef, 0x00, 		// 3630
	0xab, 0x11, 0x00, 0x4e, 0x00, 0x00, 0xff, 0xdf, 0x00, 0x4f, 		// 3640
	0x00, 0x00, 0x4f, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x4f, 0x00, 		// 3650
	0x00, 0x4f, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x10, 0xfa, 0xdf, 		// 3660
	0x05, 0xb0, 0x2b, 0xc1, 0x07, 0xf2, 0x02, 0xb0, 0x07, 0xf4, 		// 3670
	0x00, 0xb0, 0x07, 0xf2, 0x01, 0xb0, 0x07, 0xd0, 0x1a, 0xd3, 		// 3680
	0x07, 0x20, 0xfb, 0xed, 0x06, 0x20, 0x11, 0xe3, 0x03, 0xa0, 		// 3690
	0xff, 0x5d, 0x00, 0x01, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x4f, 		// 3700
	0x00, 0x00, 0x4f, 0x00, 0x00, 0xdf, 0xef, 0x07, 0x6f, 0x51, 		// 3710
	0x3f, 0x4f, 0x00, 0x7c, 0x4f, 0x00, 0x8b, 0x4f, 0x00, 0x8b, 		// 3720
	0x4f, 0x00, 0x8b, 0x4f, 0x00, 0x8b, 0xe0, 0x04, 0x70, 0x01, 		// 3730
	0x00, 0x00, 0xf0, 0x04, 0xf0, 0x04, 0xf0, 0x04, 0xf0, 0x04, 		// 3740
	0xf0, 0x04, 0xf0, 0x04, 0xf0, 0x04, 0x00, 0x4e, 0x00, 0x17, 		// 3750
	0x00, 0x00, 0x00, 0x4f, 0x00, 0x4f, 0x00, 0x4f, 0x00, 0x4f, 		// 3760
	0x00, 0x4f, 0x00, 0x4f, 0x00, 0x3f, 0x40, 0x1f, 0xec, 0x07, 		// 3770
	0x13, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x4f, 		// 3780
	0x00, 0x00, 0x4f, 0x70, 0x1d, 0x4f, 0xe6, 0x02, 0x9f, 0x2e, 		// 3790
	0x00, 0xef, 0x1d, 0x00, 0x4f, 0xcb, 0x00, 0x4f, 0xd0, 0x09, 		// 3800
	0x4f, 0x20, 0x4f, 0x13, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 		// 3810
	0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 		// 3820
	0x00, 0x6e, 0x00, 0xe6, 0x02, 0xeb, 0xdf, 0xc7, 0xef, 0x05, 		// 3830
	0x5f, 0x71, 0x5f, 0x71, 0x0f, 0x4f, 0x00, 0x3f, 0x00, 0x3f, 		// 3840
	0x4f, 0x00, 0x3f, 0x00, 0x3f, 0x4f, 0x00, 0x4f, 0x00, 0x4f, 		// 3850
	0x4f, 0x00, 0x4f, 0x00, 0x4f, 0x4f, 0x00, 0x4f, 0x00, 0x4f, 		// 3860
	0xeb, 0xef, 0x07, 0x5f, 0x51, 0x3f, 0x4f, 0x00, 0x7c, 0x4f, 		// 3870
	0x00, 0x8b, 0x4f, 0x00, 0x8b, 0x4f, 0x00, 0x8b, 0x4f, 0x00, 		// 3880
	0x8b, 0x10, 0xea, 0x7d, 0x00, 0xc0, 0x2b, 0xe4, 0x07, 0xf2, 		// 3890
	0x01, 0x60, 0x0d, 0xf4, 0x00, 0x40, 0x0f, 0xf2, 0x01, 0x60, 		// 3900
	0x0d, 0xc0, 0x2b, 0xe4, 0x07, 0x10, 0xea, 0x7e, 0x00, 0xeb, 		// 3910
	0xdf, 0x06, 0x6f, 0x51, 0x6e, 0x4f, 0x00, 0xd7, 0x4f, 0x00, 		// 3920
	0xf4, 0x4f, 0x00, 0xd6, 0x8f, 0x32, 0x8d, 0xcf, 0xee, 0x08, 		// 3930
	0x4f, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x10, 0xe9, 0xdf, 0x07, 		// 3940
	0xc0, 0x3c, 0xa1, 0x0a, 0xf2, 0x02, 0x90, 0x0a, 0xf4, 0x00, 		// 3950
	0x90, 0x0a, 0xf2, 0x01, 0x90, 0x0a, 0xc0, 0x2a, 0xc3, 0x0a, 		// 3960
	0x10, 0xfb, 0xdd, 0x0a, 0x00, 0x00, 0x90, 0x0a, 0x00, 0x00, 		// 3970
	0x90, 0x0a, 0xea, 0xbf, 0x6f, 0x21, 0x4f, 0x00, 0x4f, 0x00, 		// 3980
	0x4f, 0x00, 0x4f, 0x00, 0x4f, 0x00, 0x80, 0xfe, 0x0b, 0xe4, 		// 3990
	0x02, 0x02, 0xf3, 0x05, 0x00, 0x50, 0xdd, 0x05, 0x00, 0x50, 		// 4000
	0x2f, 0x21, 0x20, 0x3f, 0xe4, 0xef, 0x08, 0x00, 0x00, 0x00, 		// 4010
	0xf0, 0x03, 0x00, 0xf0, 0x03, 0x00, 0xf0, 0xff, 0x0c, 0xf0, 		// 4020
	0x03, 0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03, 		// 4030
	0x00, 0xd0, 0x18, 0x03, 0x40, 0xfd, 0x0c, 0xf0, 0x03, 0xc0, 		// 4040
	0x07, 0xf0, 0x03, 0xc0, 0x07, 0xf0, 0x03, 0xc0, 0x07, 0xf0, 		// 4050
	0x03, 0xc0, 0x07, 0xf0, 0x04, 0xc0, 0x07, 0xb0, 0x2b, 0xc1, 		// 4060
	0x07, 0x10, 0xfb, 0xdf, 0x04, 0xaa, 0x00, 0xf1, 0x02, 0xe5, 		// 4070
	0x00, 0xd5, 0x00, 0xf0, 0x03, 0x8a, 0x00, 0xa0, 0x08, 0x3e, 		// 4080
	0x00, 0x40, 0x5e, 0x0d, 0x00, 0x00, 0xee, 0x07, 0x00, 0x00, 		// 4090
	0xf7, 0x01, 0x00, 0xa9, 0x00, 0xb8, 0x00, 0xb7, 0xe5, 0x00, 		// 4100
	0xec, 0x00, 0x7b, 0xf1, 0x02, 0xde, 0x03, 0x3f, 0xc0, 0x47, 		// 4110
	0x9a, 0x47, 0x0e, 0x70, 0x9b, 0x46, 0x9c, 0x09, 0x10, 0xef, 		// 4120
	0x01, 0xee, 0x03, 0x00, 0xbb, 0x00, 0xd9, 0x00, 0xe5, 0x01, 		// 4130
	0xd6, 0x00, 0xa0, 0x1a, 0x3e, 0x00, 0x10, 0xde, 0x08, 0x00, 		// 4140
	0x00, 0xfa, 0x03, 0x00, 0x40, 0x8e, 0x0d, 0x00, 0xd0, 0x05, 		// 4150
	0x8c, 0x00, 0xb7, 0x00, 0xf2, 0x02, 0xa9, 0x00, 0xf2, 0x01, 		// 4160
	0xe4, 0x00, 0xc6, 0x00, 0xe0, 0x04, 0x8a, 0x00, 0x90, 0x0a, 		// 4170
	0x3f, 0x00, 0x20, 0x6f, 0x0d, 0x00, 0x00, 0xfa, 0x07, 0x00, 		// 4180
	0x00, 0xf3, 0x01, 0x00, 0x11, 0x9a, 0x00, 0x00, 0xfc, 0x0a, 		// 4190
	0x00, 0x00, 0xf5, 0xff, 0x8f, 0x00, 0x60, 0x2e, 0x00, 0xf2, 		// 4200
	0x04, 0x00, 0x8c, 0x00, 0x80, 0x0d, 0x00, 0xf2, 0x04, 0x00, 		// 4210
	0xf8, 0xff, 0xaf, 0x00, 0xe7, 0x03, 0x20, 0x2f, 0x00, 0x40, 		// 4220
	0x0d, 0x00, 0x40, 0x0d, 0x00, 0x40, 0x0d, 0x00, 0x80, 0x0a, 		// 4230
	0x00, 0xf7, 0x03, 0x00, 0x80, 0x0a, 0x00, 0x40, 0x0d, 0x00, 		// 4240
	0x40, 0x0d, 0x00, 0x40, 0x0d, 0x00, 0x20, 0x2f, 0x00, 0x00, 		// 4250
	0xe8, 0x03, 0x35, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 		// 4260
	0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0xbd, 0x01, 0xb0, 0x07, 0x80, 		// 4270
	0x09, 0x80, 0x0a, 0x70, 0x0a, 0x50, 0x1d, 0x00, 0xdd, 0x50, 		// 4280
	0x1d, 0x70, 0x0a, 0x80, 0x0a, 0x80, 0x09, 0xb0, 0x08, 0xbd, 		// 4290
	0x01, 0xa0, 0x9d, 0x31, 0x07, 0xa4, 0x82, 0xff, 0x04, 0x00, 		// 4300
	0x00, 0x00, 0x00, 0xa8, 0xb9, 0xeb, 0x00, 0x88, 0xb4, 0xec, 		// 4310
	0x00, 0xb8, 0x85, 0xeb, 0x00, 0x91, 0x9e, 0xeb, 0x00, 0x8c, 		// 4320
	0x8c, 0xed, 0x00, 0x95, 0xb0, 0xea, 0x00, 0x9d, 0xa1, 0xeb, 		// 4330
	0x00, 0x00, 0x11, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x48, 0x11, 		// 4340
	0x00, 0x00, 0x0c, 0x0b, 0x00, 0x8a, 0x11, 0x00, 0x00, 0x0c, 		// 4350
	0x0a, 0x01, 0x40, 0x30, 0x32, 0x40, 0xd1, 0x01, 0xf1, 0xb0, 		// 4360
	0xb5, 0xf0, 0xf2, 0x01, 0xf1, 0xe9, 0xe5, 0xf9, 0xf2, 0x25, 		// 4370
	0xf1, 0xc3, 0xc5, 0xf3, 0xf2, 0x49, 0xf1, 0xc3, 0xc5, 0xf3, 		// 4380
	0xf2, 0x01, 0xa1, 0xaa, 0xa4, 0xaa, 0xf2, 0x01, 0x00, 0x22, 		// 4390
	0x22, 0x22, 0x83, 0x01, 0x00, 0xa6, 0xaa, 0xaa, 0xfa, 0x01, 		// 4400
	0x00, 0x32, 0x33, 0x33, 0xf4, 0x01, 0x00, 0xb7, 0x88, 0x88, 		// 4410
	0x88, 0x01, 0x00, 0x87, 0x22, 0x22, 0x22, 0x01, 0x00, 0xa6, 		// 4420
	0xaa, 0xaa, 0xaa, 0x05, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 		// 4430
	0x00, 0x11, 0x81, 0x18, 0x11, 0x00, 0x40, 0xff, 0xff, 0xff, 		// 4440
	0xff, 0x04, 0x00, 0x00, 0xa0, 0x09, 0x00, 0x00, 0x00, 0x00, 		// 4450
	0xe3, 0x2e, 0x00, 0x00, 0x00, 0x50, 0x4e, 0xd5, 0x05, 0x00, 		// 4460
	0x70, 0x8e, 0x22, 0x22, 0xe8, 0x06, 0x10, 0x00, 0x70, 0x07, 		// 4470
	0x00, 0x01, 0x00, 0x00, 0x70, 0x07, 0x00, 0x00, 0x72, 0x77, 		// 4480
	0xb7, 0x7b, 0x77, 0x27, 0x52, 0x55, 0x55, 0x55, 0x55, 0x25, 		// 4490
	0x10, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x00, 0x00, 		// 4500
	0x00, 0x00, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 		// 4510
	0x00, 0x00, 0x00, 0x00, 0x10, 0x8f, 0x77, 0x77, 0x77, 0x01, 		// 4520
	0x00, 0x44, 0xa4, 0x4a, 0x44, 0x00, 0x00, 0x00, 0x70, 0x07, 		// 4530
	0x00, 0x00, 0x00, 0x00, 0x70, 0x07, 0x00, 0x00, 0x73, 0x77, 		// 4540
	0xb7, 0x7b, 0x77, 0x27, 0x42, 0x44, 0x44, 0x44, 0x44, 0x14, 		// 4550
	0xcd, 0x11, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x22, 0x22, 0x12, 		// 4560
	0x40, 0x0a, 0x00, 0xbb, 0xbb, 0x6e, 0x40, 0x0b, 0x00, 0x00, 		// 4570
	0x00, 0x69, 0x40, 0x0b, 0x00, 0xba, 0xbb, 0x6e, 0x40, 0xff, 		// 4580
	0x06, 0x5c, 0x11, 0x11, 0x40, 0x1b, 0x00, 0x7c, 0x55, 0x86, 		// 4590
	0x46, 0x0b, 0x00, 0x77, 0x67, 0x45, 0x42, 0x0b, 0x00, 0x00, 		// 4600
	0x40, 0x55, 0x24, 0x02, 0x00, 0x30, 0x8d, 0x66, 0xd8, 0x04, 		// 4610
	0x00, 0xa0, 0x05, 0x00, 0x40, 0x0c, 0x00, 0x70, 0x3a, 0x22, 		// 4620
	0x93, 0x07, 0x00, 0x00, 0x94, 0xcb, 0x59, 0x00, 0x00, 0x1c, 		// 4630
	0x12, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 4640
	0x95, 0x00, 0x81, 0x88, 0x88, 0x38, 0x95, 0x00, 0x41, 0x6f, 		// 4650
	0xf4, 0x26, 0x95, 0x00, 0x00, 0x2f, 0xf0, 0x02, 0x95, 0x00, 		// 4660
	0x00, 0x2f, 0xf0, 0x02, 0xb5, 0x23, 0x00, 0x2f, 0xf0, 0x02, 		// 4670
	0xe5, 0x7a, 0x00, 0x2f, 0xf0, 0x02, 0x95, 0x00, 0x10, 0x3f, 		// 4680
	0xf2, 0x34, 0x95, 0x00, 0xf5, 0xff, 0xbe, 0x89, 0x96, 0x00, 		// 4690
	0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 		// 4700
	0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x72, 0x12, 		// 4710
	0x00, 0x00, 0x0c, 0x0c, 0x00, 0xba, 0x12, 0x00, 0x00, 0x0c, 		// 4720
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, 0x00, 0xc0, 0xff, 		// 4730
	0xff, 0x06, 0xb4, 0x00, 0x00, 0x00, 0xa0, 0x04, 0xb4, 0x00, 		// 4740
	0x00, 0x00, 0xd2, 0x01, 0xf4, 0x6d, 0x00, 0x10, 0x4c, 0x00, 		// 4750
	0xb4, 0x11, 0x10, 0xe6, 0x04, 0x00, 0xb4, 0x00, 0xf2, 0x28, 		// 4760
	0x00, 0x00, 0xb4, 0x00, 0x10, 0x20, 0x97, 0x79, 0x24, 0x00, 		// 4770
	0x00, 0xd4, 0x35, 0x53, 0x6b, 0x00, 0x00, 0x69, 0x00, 0x00, 		// 4780
	0xd3, 0x00, 0x00, 0xb5, 0x24, 0x42, 0x7a, 0x00, 0x00, 0x30, 		// 4790
	0xb8, 0x9c, 0x04, 0x00, 0x00, 0x77, 0x77, 0x77, 0x77, 0x00, 		// 4800
	0x00, 0x44, 0x44, 0x44, 0xf6, 0x00, 0x00, 0x66, 0x66, 0x66, 		// 4810
	0xf8, 0x00, 0x00, 0x6f, 0x44, 0x44, 0x44, 0x00, 0x00, 0x8f, 		// 4820
	0x66, 0x66, 0x66, 0x01, 0x00, 0x55, 0xa5, 0x5a, 0x55, 0x01, 		// 4830
	0x62, 0x66, 0xb6, 0x6a, 0x66, 0x26, 0x62, 0x66, 0x66, 0x66, 		// 4840
	0x66, 0x26, 0x20, 0x99, 0x99, 0x99, 0x99, 0x00, 0x00, 0x33, 		// 4850
	0x33, 0x33, 0xf5, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x01, 		// 4860
	0x00, 0x00, 0x00, 0x00, 0xa1, 0x00
};

YssFontHeaderPartUnicode *Font_Ubuntu_10 = (YssFontHeaderPartUnicode*)Ubuntu_10;

