/**
  * Audio Spectrum Analyzer
  * Author: Jan Szemiet
  */

/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
#include "arm_math.h"               // Required to use float32_t type
#include "stm32f4_discovery.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_adc.h"
#include "pwm.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#define	SAMPLES 1024
#define FFT_SIZE SAMPLES/2

int32_t a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17;

float32_t getAdc(){
	float32_t L = TM_ADC_Read(ADC1, ADC_Channel_0);
	float32_t R = TM_ADC_Read(ADC1, ADC_Channel_1);
	float32_t arg = (L+R)/2/3095;
	return arg;
}

void jebnijBasemNaNixie(int32_t* koniec){

	TIM4->CCR1 = koniec[0];
	TIM4->CCR2 = koniec[1];
	TIM4->CCR3 = koniec[2];
	TIM4->CCR4 = koniec[3];

	TIM3->CCR1 = koniec[4];
	TIM3->CCR2 = koniec[5];
	TIM3->CCR3 = koniec[6];
	TIM3->CCR4 = koniec[7];

	TIM2->CCR1 = koniec[8];
	TIM2->CCR2 = koniec[9];
	TIM2->CCR3 = koniec[10];
	TIM2->CCR4 = koniec[11];

	TIM1->CCR1 = koniec[12];
	TIM1->CCR2 = koniec[13];
	TIM1->CCR3 = koniec[14];
	TIM1->CCR4 = koniec[15];

	TIM9->CCR1 = 20;
	TIM9->CCR2 = koniec[17];
}


arm_rfft_instance_f32 S;
arm_cfft_radix4_instance_f32 S_CFFT;

int main(void)
{
	initClocks();
	initTIM1();
	initTIM2();
	initTIM3();
	initTIM4();
	initTIM9();


	float32_t bInput[SAMPLES];
	float32_t bOutput[SAMPLES];
	float32_t bOutputMag[SAMPLES];
	float32_t maxValue;
	int32_t koniec[18];
	uint32_t  maxIndex;
	TM_ADC_Init(ADC1, ADC_Channel_0);
  	TM_ADC_Init(ADC1, ADC_Channel_1);

	arm_rfft_init_f32(&S, &S_CFFT, FFT_SIZE, 0, 1);

  	while(1)
  	{
  	     for (int i = 0; i < SAMPLES; i++) {
  	         bInput[i] = getAdc();
	     }

  	     arm_rfft_f32(&S, bInput, bOutput);

  	     arm_cmplx_mag_f32(bOutput, bOutputMag, FFT_SIZE);

  	     arm_max_f32(bOutputMag, FFT_SIZE, &maxValue, &maxIndex);

  	     if(maxValue < 0.5){
  	    	 maxValue = 0.5;
  	     }else if(maxValue > 3){
  	    	 maxValue=3;
  	     }

  	     for(int i=0; i<FFT_SIZE; ++i){
  	    	 bOutputMag[i] = 84*bOutputMag[i]/maxValue;
  	     }

		koniec[0] = (int32_t)bOutputMag[1];
		 koniec[1] = (int32_t)bOutputMag[2];
		 koniec[2] = (int32_t)bOutputMag[3];
		 koniec[3] = (int32_t)bOutputMag[4];

		 koniec[4] = (int32_t)((bOutputMag[5]+bOutputMag[6])/2);
		 koniec[5] = (int32_t)((bOutputMag[7]+bOutputMag[8])/2);

		 koniec[6] = (int32_t)((bOutputMag[9]+bOutputMag[10])/2);

		 koniec[7] = (int32_t)((bOutputMag[11]+bOutputMag[12])/2);

		 int32_t suma=0;
		 for(int i=16; i<20; i++){
			 suma+=bOutputMag[i];
		 }

		 koniec[8] = (int32_t)(suma/2);

		suma=0;
		for(int i=20; i<24; i++){
				 suma+=bOutputMag[i];
		 }

		koniec[9] = (int32_t)(suma/2);

		suma=0;
		for(int i=24; i<34; i++){
			 suma+=bOutputMag[i];
		}

		koniec[10] = (int32_t)(suma/3);

		suma=0;
		for(int i=34; i<44; i++){
			 suma+=bOutputMag[i];
		}

		koniec[11] = (int32_t)(suma/3);

		suma=0;
		for(int i=44; i<56; i++){
			 suma+=bOutputMag[i];
		}

		koniec[12] = (int32_t)(suma/5);

		suma=0;
		for(int i=56; i<74; i++){
			 suma+=bOutputMag[i];
		}

		koniec[13] = (int32_t)(suma/8);

		suma=0;
		for(int i=74; i<94; i++){
			 suma+=bOutputMag[i];
		}

		koniec[14] = (int32_t)(suma/8);

		suma=0;
		for(int i=94; i<120; i++){
			 suma+=bOutputMag[i];
		}

		koniec[15] = (int32_t)(suma/8);

		suma=0;
		for(int i=120; i<146; i++){
			 suma+=bOutputMag[i];
		}

		koniec[16] = (int32_t)(suma/8);

		suma=0;
		for(int i=146; i<256; i++){
			 suma+=bOutputMag[i];
		}

		koniec[17] = (int32_t)(suma/50);


  	jebnijBasemNaNixie(koniec);

  	a0=koniec[0];
  	a1=koniec[1];
  	a2=koniec[2];
  	a3=koniec[3];
  	a4=koniec[4];
  	a5=koniec[5];
  	a6=koniec[6];
  	a7=koniec[7];
  	a8=koniec[8];
  	a9=koniec[9];
  	a10=koniec[10];
  	a11=koniec[11];
  	a12=koniec[12];
  	a13=koniec[13];
  	a14=koniec[14];
  	a15=koniec[15];
  	a16=koniec[16];
  	a17=koniec[17];

  	for(int i=0; i<100000; i++);
  	}
}




