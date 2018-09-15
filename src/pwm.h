
/*
ADC:
	NR		PIN			ADC			CHANNEL
	0		PA1			ADC1		1
	1		PA2			ADC1		2

PWM:
	NR		PIN			TIMER		CHANNEL

	0		PD12		TIM4		CH1
	1		PD13		TIM4		CH2
	2		PD14		TIM4		CH3
	3		PD15		TIM4		CH4

	4		PC6			TIM3		CH1
	5		PC7			TIM3		CH2
	6		PC8			TIM3		CH3
	7		PC9			TIM3		CH4

	8		PA15		TIM2		CH1
	9		PB3			TIM2		CH2
	10		PA2			TIM2		CH3
	11		PB11		TIM2		CH4

	12		PA8			TIM1		CH1
	13		PA9			TIM1		CH2
	14		PA10		TIM1		CH3
	15		PE14		TIM1		CH4

	16		PE5			TIM9		CH1
	17		PE6			TIM9		CH2



RCC:
	TIM 1,9 -> APB2
	TIM 2,3,4 -> APB1
 */

#ifndef PWM_H_
#define PWM_H_

void initClocks();
void initTIM1();
void initTIM2();
void initTIM3();
void initTIM4();
void initTIM9();

#endif /* PWM_H_ */
