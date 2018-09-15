#include <math.h>
#include <stdio.h>
#include "arm_math.h"               // Required to use float32_t type
#include "stm32f4_discovery.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_adc.h"
#include "pwm.h"

#define	SAMPLES 1024
#define FFT_SIZE SAMPLES/2

float32_t getAdc(){
	float32_t L = TM_ADC_Read(ADC1, ADC_Channel_0);
	float32_t R = TM_ADC_Read(ADC1, ADC_Channel_1);
	float32_t arg = (L+R)/2;
	return arg;
}

void dropTheBass(int32_t* endTable){

	TIM4->CCR1 = endTable[0];
	TIM4->CCR2 = endTable[1];
	TIM4->CCR3 = endTable[2];
	TIM4->CCR4 = endTable[3];

	TIM3->CCR1 = endTable[4];
	TIM3->CCR2 = endTable[5];
	TIM3->CCR3 = endTable[6];
	TIM3->CCR4 = endTable[7];

	TIM2->CCR1 = endTable[8];
	TIM2->CCR2 = endTable[9];
	TIM2->CCR3 = endTable[10];
	TIM2->CCR4 = endTable[11];

	TIM1->CCR1 = endTable[12];
	TIM1->CCR2 = endTable[13];
	TIM1->CCR3 = endTable[14];
	TIM1->CCR4 = endTable[15];

	TIM9->CCR1 = endTable[16];
	TIM9->CCR2 = endTable[17];
}


arm_rfft_instance_f32 S;
arm_cfft_radix4_instance_f32 S_CFFT;

int main(void)
{
	TM_ADC_Init(ADC1, ADC_Channel_0);
	TM_ADC_Init(ADC1, ADC_Channel_1);


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

	int32_t endTable[18];
	int32_t last[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int32_t last2[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	uint32_t  maxIndex;

	arm_rfft_init_f32(&S, &S_CFFT, FFT_SIZE, 0, 1);

  	while(1)
  	{
  		 for (int i = 0; i < SAMPLES; i++) {
  		  	         bInput[i] = getAdc();
  			     }

  		  	     arm_rfft_f32(&S, bInput, bOutput);

  		  	     arm_cmplx_mag_f32(bOutput, bOutputMag, FFT_SIZE);

  		  	     arm_max_f32(bOutputMag, FFT_SIZE, &maxValue, &maxIndex);

  		  	     for(int i=0; i<FFT_SIZE; ++i){
  		  	    	 bOutputMag[i] = 84*bOutputMag[i]/maxValue;
  		  	     }

  				 endTable[0] = (int32_t)bOutputMag[1];
  				 endTable[1] = (int32_t)bOutputMag[2];
  				 endTable[2] = (int32_t)bOutputMag[3];
  				 endTable[3] = (int32_t)bOutputMag[4];

  				 endTable[4] = (int32_t)((bOutputMag[5]+bOutputMag[6])/2);
  				 endTable[5] = (int32_t)((bOutputMag[7]+bOutputMag[8])/2);

  				 endTable[6] = (int32_t)((bOutputMag[9]+bOutputMag[10])/2);

  				 endTable[7] = (int32_t)((bOutputMag[11]+bOutputMag[12])/2);

  				 int32_t sum=0;
  				 for(int i=16; i<20; i++){
  					 sum+=bOutputMag[i];
  				 }

  				 endTable[8] = (int32_t)(sum/2);

  				sum=0;
  				for(int i=20; i<24; i++){
  						 sum+=bOutputMag[i];
  				 }

  				endTable[9] = (int32_t)(sum/2);

  				sum=0;
  				for(int i=24; i<34; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[10] = (int32_t)(sum/3);

  				sum=0;
  				for(int i=34; i<44; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[11] = (int32_t)(sum/3);

  				sum=0;
  				for(int i=44; i<56; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[12] = (int32_t)(sum/5);

  				sum=0;
  				for(int i=56; i<74; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[13] = (int32_t)(sum/8);

  				sum=0;
  				for(int i=74; i<94; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[14] = (int32_t)(sum/8);

  				sum=0;
  				for(int i=94; i<120; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[15] = (int32_t)(sum/8);

  				sum=0;
  				for(int i=120; i<146; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[16] = (int32_t)(sum/8);

  				sum=0;
  				for(int i=146; i<512; i++){
  					 sum+=bOutputMag[i];
  				}

  				endTable[17] = (int32_t)(sum/50);


  			for(int i=0; i<18; i++){
  				endTable[i] = (endTable[i]+last[i]+last2[i])/3;
  			}
  		  	dropTheBass(endTable);
  			for(int i=0; i<100000; i++);
  			for(int i=0; i<18; i++){
  					last2[i] = last[i];
  			  		last[i] = endTable[i];
  			  }

  	}
}
