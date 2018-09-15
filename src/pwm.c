#include "stm32f4_discovery.h"
#include "stm32f4xx.h"

int period = 83;
int prescaler = 999999;

void initClocks(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE , ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_TIM9, ENABLE);
}

void initTIM1(){
	GPIO_InitTypeDef initA;
	initA.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	initA.GPIO_Mode = GPIO_Mode_OUT;
	initA.GPIO_OType = GPIO_OType_PP;
	initA.GPIO_Speed = GPIO_Speed_100MHz;
	initA.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &initA);

	GPIO_InitTypeDef initE;
	initE.GPIO_Pin = GPIO_Pin_14;
	initE.GPIO_Mode = GPIO_Mode_OUT;
	initE.GPIO_OType = GPIO_OType_PP;
	initE.GPIO_Speed = GPIO_Speed_100MHz;
	initE.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &initE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM1, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);
    initA.GPIO_Pin = GPIO_Pin_8;
    initA.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &initA);

    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_TIM1);
    initA.GPIO_Pin = GPIO_Pin_9;
    initA.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &initA);

    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_TIM1);
    initA.GPIO_Pin = GPIO_Pin_10;
    initA.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &initA);

    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);
    initE.GPIO_Pin = GPIO_Pin_14;
    initE.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOE, &initE);
}

void initTIM2(){
	GPIO_InitTypeDef initA;
	initA.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_15;
	initA.GPIO_Mode = GPIO_Mode_OUT;
	initA.GPIO_OType = GPIO_OType_PP;
	initA.GPIO_Speed = GPIO_Speed_100MHz;
	initA.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &initA);

	GPIO_InitTypeDef initB;
	initB.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_11;
	initB.GPIO_Mode = GPIO_Mode_OUT;
	initB.GPIO_OType = GPIO_OType_PP;
	initB.GPIO_Speed = GPIO_Speed_100MHz;
	initB.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &initB);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM2, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);
    initA.GPIO_Pin = GPIO_Pin_15;
    initA.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &initA);

    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);
    initB.GPIO_Pin = GPIO_Pin_3;
    initB.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOB, &initB);

    TIM_OC3Init(TIM2, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);
    initA.GPIO_Pin = GPIO_Pin_2;
    initA.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &initA);

    TIM_OC4Init(TIM2, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);
    initB.GPIO_Pin = GPIO_Pin_11;
    initB.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOB, &initB);
}

void initTIM3(){
	GPIO_InitTypeDef initC;
	initC.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	initC.GPIO_Mode = GPIO_Mode_OUT;
	initC.GPIO_OType = GPIO_OType_PP;
	initC.GPIO_Speed = GPIO_Speed_100MHz;
	initC.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &initC);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM3, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
    initC.GPIO_Pin = GPIO_Pin_6;
    initC.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOC, &initC);

    TIM_OC2Init(TIM3, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);
    initC.GPIO_Pin = GPIO_Pin_7;
    initC.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOC, &initC);

    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);
    initC.GPIO_Pin = GPIO_Pin_8;
    initC.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOC, &initC);

    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM3);
    initC.GPIO_Pin = GPIO_Pin_9;
    initC.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOC, &initC);
}

void initTIM4(){
	GPIO_InitTypeDef initD;
	initD.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	initD.GPIO_Mode = GPIO_Mode_OUT;
	initD.GPIO_OType = GPIO_OType_PP;
	initD.GPIO_Speed = GPIO_Speed_100MHz;
	initD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &initD);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM4, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
    initD.GPIO_Pin = GPIO_Pin_12;
    initD.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOD, &initD);

    TIM_OC2Init(TIM4, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
    initD.GPIO_Pin = GPIO_Pin_13;
    initD.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOD, &initD);

    TIM_OC3Init(TIM4, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
    initD.GPIO_Pin = GPIO_Pin_14;
    initD.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOD, &initD);

    TIM_OC4Init(TIM4, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);
    initD.GPIO_Pin = GPIO_Pin_15;
    initD.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOD, &initD);
}

void initTIM9(){
	GPIO_InitTypeDef initE;
	initE.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	initE.GPIO_Mode = GPIO_Mode_OUT;
	initE.GPIO_OType = GPIO_OType_PP;
	initE.GPIO_Speed = GPIO_Speed_100MHz;
	initE.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &initE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM9, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM9, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM9, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);
    initE.GPIO_Pin = GPIO_Pin_5;
    initE.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOE, &initE);

    TIM_OC2Init(TIM9, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);
    initE.GPIO_Pin = GPIO_Pin_6;
    initE.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOE, &initE);

}
