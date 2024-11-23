/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GPIO_ALTFUNC_STM32F1__H_
#define YSS_GPIO_ALTFUNC_STM32F1__H_

typedef enum
{
	PA0_WKUP,
	PA0_USART2_CTS,
	PA0_TIM2_CH1_ETR,
	PA0_TIM5_CH1,
	PA0_CAPTURE5_CH1,
	PA0_TIM8_ETR,
	PA1_USART2_RTS,
	PA1_TIM5_CH2,
	PA1_CAPTURE5_CH2,
	PA1_TIM2_CH2,
	PA1_CAPTURE2_CH2,
	PA2_USART2_TX,
	PA2_TIM5_CH3,
	PA2_CAPTURE5_CH3,
	PA2_TIM9_CH1,
	PA2_CAPTURE9_CH1,
	PA2_TIM2_CH3,
	PA2_CAPTURE2_CH3,
	PA3_USART2_RX,
	PA3_TIM5_CH4,
	PA3_CAPTURE5_CH4,
	PA3_TIM2_CH4,
	PA3_CAPTURE2_CH4,
	PA3_TIM9_CH2,
	PA3_CAPTURE9_CH2,
	PA4_SPI1_NSS,
	PA4_USART2_CK,
	PA4_DAC_OUT1,
	PA5_SPI1_SCK,
	PA5_DAC_OUT2,
	PA6_SPI1_MISO,
	PA6_TIM8_BKIN,
	PA6_TIM3_CH1,
	PA6_CAPTURE3_CH1,
	PA6_TIM13_CH1,
	PA6_CAPTURE13_CH1,
	PA7_SPI1_MOSI,
	PA7_TIM8_CH1N,
	PA7_CAPTURE8_CH1N,
	PA7_TIM3_CH2,
	PA7_CAPTURE3_CH2,
	PA7_TIM14_CH1,
	PA7_CAPTURE14_CH1,
	PA8_USART1_CK,
	PA8_TIM1_CH1,
	PA8_CAPTURE1_CH1,
	PA8_MCO,
	PA9_USART1_TX,
	PA9_TIM1_CH2,
	PA10_CAPTURE1_CH2,
	PA10_USART1_RX,
	PA10_TIM1_CH3,
	PA10_CAPTURE1_CH3,
	PA11_USART1_CTS,
	PA11_USB_DM,
	PA11_CAN_RX,
	PA11_TIM1_CH4,
	PA11_CAPTURE1_CH4,
	PA12_USART1_RTS,
	PA12_USB_DP,
	PA12_CAN_TX,
	PA12_TIM1_ETR,
	PA13,
	PA13_JTMS_SWDIO,
	PA14,
	PA14_JTCK_SWCLK,
	PA15,
	PA15_JTDI,
	PA15_SPI3_NSS,
	PA15_I2S3_WS,
	PA15_TIM2_CH1_ETR,
	PA15_CAPTURE2_CH1,
	PA15_SPI1_NSS,

	PB0_TIM3_CH3,
	PB0_CAPTURE3_CH3,
	PB0_TIM8_CH2N,
	PB0_CAPTURE8_CH2N,
	PB0_TIM1_CH2N,
	PB0_CAPTURE1_CH2,
	PB1_TIM3_CH4,
	PB1_CAPTURE3_CH4,
	PB1_TIM8_CH3N,
	PB1_CAPTURE8_CH3N,
	PB1_TIM1_CH3N,
	PB1_CAPTURE1_CH3N,
	PB3,
	PB3_SPI3_SCK,
	PB3_I2S3_CK,
	PB3_TRACESWO,
	PB3_TIM2_CH2,
	PB3_CAPTURE2_CH2,
	PB3_SPI1_SCK,
	PB4,
	PB4_SPI3_MISO,
	PB4_TIM3_CH1,
	PB4_CAPTURE3_CH1,
	PB4_SPI1_MISO,
	PB5_I2C1_SMBA,
	PB5_SPI3_MOSI,
	PB5_I2S3_SD,
	PB5_TIM3_CH2,
	PB5_CAPTURE3_CH2,
	PB5_SPI1_MOSI,
	PB6_I2C1_SCL,
	PB6_TIM4_CH1,
	PB6_CAPTURE4_CH1,
	PB6_USART1_TX,
	PB7_I2C1_SDA,
	PB7_FSMC_NADV,
	PB7_TIM4_CH2,
	PB7_CAPTURE4_CH2,
	PB7_USART1_RX,
	PB8_TIM4_CH3,
	PB8_CAPTURE4_CH3,
	PB8_SDIO_D4,
	PB8_TIM10_CH1,
	PB8_CAPTURE10_CH1,
	PB8_I2C1_SCL,
	PB8_CAN_RX,
	PB9_TIM4_CH4,
	PB9_CAPTURE4_CH4,
	PB9_SDIO_D5,
	PB9_TIM11_CH1,
	PB9_CAPTURE1_CH1,
	PB9_I2C1_SDA,
	PB9_CAN_TX,
	PB10_I2C2_SCL,
	PB10_USART3_TX,
	PB10_TIM2_CH3,
	PB10_CAPTURE2_CH3,
	PB11_I2C2_SDA,
	PB11_USART3_RX,
	PB11_TIM2_CH4,
	PB11_CAPTURE2_CH4,
	PB12_SPI2_NSS,
	PB12_I2S2_WS,
	PB12_I2C2_SMBA,
	PB12_USART3_CK,
	PB12_TIM1_BKIN,
	PB13_SPI2_SCK,
	PB13_I2S2_CK,
	PB13_USART3_CTS,
	PB13_TIM1_CH1N,
	PB13_CAPTURE1_CH1N,
	PB14_SPI2_MISO,
	PB14_TIM1_CH2N,
	PB14_CAPTURE1_CH2N,
	PB14_USART3_RTS,
	PB14_TIM12_CH1,
	PB14_CAPTURE12_CH1,
	PB15_SPI2_MOSI,
	PB15_I2S2_SD,
	PB15_TIM1_CH3N,
	PB15_CAPTURE1_CH3N,
	PB15_TIM12_CH2,
	PB15_CAPTURE12_CH2,

	PC6_I2S2_MCK,
	PC6_TIM8_CH1,
	PC6_CAPTURE8_CH1,
	PC6_SDIO_D6,
	PC6_TIM3_CH1,
	PC6_CAPTURE3_CH1,
	PC7_I2S3_MCK,
	PC7_TIM8_CH2,
	PC7_CAPTURE8_CH2,
	PC7_SDIO_D7,
	PC7_TIM3_CH2,
	PC7_CAPTURE3_CH2,
	PC8_TIM8_CH3,
	PC8_CAPTURE8_CH3,
	PC8_SDIO_D0,
	PC8_TIM3_CH3,
	PC8_CAPTURE3_CH3,
	PC9_TIM8_CH4,
	PC9_CAPTURE3_CH3,
	PC9_SDIO_D1,
	PC9_TIM3_CH4,
	PC9_CAPTURE3_CH4,
	PC10_UART4_TX,
	PC10_SDIO_D2,
	PC10_USART3_TX,
	PC11_UART4_RX,
	PC11_SDIO_D3,
	PC11_USART3_RX,
	PC12_UART5_TX,
	PC12_SDIO_CK,
	PC12_USART3_CK,
	PC13_TAMPER_RTC,
	PC14_OSC32_IN,
	PC15_OSC32_OUT,

	PD0,
	PD0_FSMC_D2,
	PD0_CAN_RX,
	PD0_OSC_IN,
	PD1,
	PD1_FSMC_D3,
	PD1_CAN_TX,
	PD1_OSC_OUT,
	PD2_TIM3_ETR,
	PD2_USART5_RX,
	PD2_SDIO_CMD,
	PD3_FSMC_CLK,
	PD3_USART2_CTS,
	PD4_FSMC_NOE,
	PD4_USART2_RTS,
	PD5_FSMC_NWE,
	PD5_USART2_TX,
	PD6_FSMC_NWAIT,
	PD6_USART2_RX,
	PD7_FSMC_NE1,
	PD7_FSMC_NCE2,
	PD7_USART2_CK,
	PD8_FSMC_D13,
	PD8_USART3_TX,
	PD9_FSMC_D14,
	PD9_USART3_RX,
	PD10_FSMC_D15,
	PD10_USART3_CK,
	PD11_FSMC_A16,
	PD11_USART3_CTS,
	PD12_FSMC_A17,
	PD12_TIM4_CH1,
	PD12_CAPTURE4_CH1,
	PD12_USART3_RTS,
	PD13_FSMC_A18,
	PD13_TIM4_CH2,
	PD13_CAPTURE4_CH2,
	PD14_FSMC_D0,
	PD14_TIM4_CH3,
	PD14_CAPTURE4_CH3,
	PD15_FSMC_D1,
	PD15_TIM4_CH4,
	PD15_CAPTURE4_CH4,

	PE0_TIM4_ETR,
	PE2_TRACECK,
	PE2_FSMC_A23,
	PE3_TRACED0,
	PE3_FSMC_A19,
	PE4_TRACED1,
	PE4_FSMC_A20,
	PE5_TRACED2,
	PE5_FSMC_A21,
	PE5_TIM9_CH1,
	PE5_CAPTURE9_CH1,
	PE6_TRACED3,
	PE6_FSMC_A22,
	PE6_TIM9_CH2,
	PE6_CAPTURE9_CH2,
	PE7_FSMC_D4,
	PE7_TIM1_ETR,
	PE8_FSMC_D5,
	PE8_TIM1_CH1N,
	PE8_CAPTURE1_CH1N,
	PE9_FSMC_D6,
	PE9_TIM1_CH1,
	PE9_CAPTURE1_CH1,
	PE10_FSMC_D7,
	PE10_TIM1_CH2N,
	PE10_CAPTURE1_CH2N,
	PE11_FSMC_D8,
	PE11_TIM1_CH2,
	PE11_CAPTURE1_CH2,
	PE12_FSMC_D9,
	PE12_TIM1_CH3N,
	PE12_CAPTURE1_CH3N,
	PE13_FSMC_D10,
	PE13_TIM1_CH3,
	PE13_CAPTURE1_CH3,
	PE14_FSMC_D11,
	PE14_TIM1_CH4,
	PE14_CAPTURE1_CH4,
	PE15_FSMC_D12,
	PE15_TIM1_BKIN,

	PF0_FSMC_A0,
	PF1_FSMC_A1,
	PF2_FSMC_A2,
	PF3_FSMC_A3,
	PF4_FSMC_A4,
	PF5_FSMC_A5,
	PF6_FSMC_NIORD,
	PF6_TIM10_CH1,
	PF6_CAPTURE10_CH1,
	PF7_FSMC_NREG,
	PF7_TIM11_CH1,
	PF7_CAPTURE11_CH1,
	PF8_FSMC_NIOWR,
	PF8_TIM13_CH1,
	PF8_CAPTURE13_CH1,
	PF9_FSMC_CD,
	PF9_TIM14_CH1,
	PF9_CAPTURE14_CH1,
	PF10_FSMC_INTR,
	PF11_FSMC_NIOS16,
	PF12_FSMC_A6,
	PF13_FSMC_A7,
	PF14_FSMC_A8,
	PF15_FSMC_A9,

	PG0_FSMC_A10,
	PG1_FSMC_A11,
	PG2_FSMC_A12,
	PG3_FSMC_A13,
	PG4_FSMC_A14,
	PG5_FSMC_A15,
	PG6_FSMC_INT2,
	PG7_FSMC_INT3,
	PG9_FSMC_NE2,
	PG9_FSMC_NCE3,
	PG10_NCE4_1,
	PG10_NE3,
	PG11_NCE4_2,
	PG12_NE4,
	PG13_A24,
	PG14_A25,
}altFunc_t;

typedef enum
{
	OSPEED_LOW = 2,
	OSPEED_MID = 1,
	OSPEED_FAST = 3,
}ospeed_t;

typedef enum
{
	OTYPE_PUSH_PULL = 0,
	OTYPE_OPEN_DRAIN = 1,
}otype_t;

typedef struct
{
	YSS_GPIO_Peri *port;
	uint8_t pin;
	altFunc_t func;
}altFuncPort_t;

typedef enum
{
	PUPD_NONE = 0,
	PUPD_PULL_UP,
	PUPD_PULL_DOWN
}pupd_t;

#endif
