################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Source/FastMathFunctions/arm_cos_f32.c \
../src/Source/FastMathFunctions/arm_cos_q15.c \
../src/Source/FastMathFunctions/arm_cos_q31.c \
../src/Source/FastMathFunctions/arm_sin_f32.c \
../src/Source/FastMathFunctions/arm_sin_q15.c \
../src/Source/FastMathFunctions/arm_sin_q31.c \
../src/Source/FastMathFunctions/arm_sqrt_q15.c \
../src/Source/FastMathFunctions/arm_sqrt_q31.c 

OBJS += \
./src/Source/FastMathFunctions/arm_cos_f32.o \
./src/Source/FastMathFunctions/arm_cos_q15.o \
./src/Source/FastMathFunctions/arm_cos_q31.o \
./src/Source/FastMathFunctions/arm_sin_f32.o \
./src/Source/FastMathFunctions/arm_sin_q15.o \
./src/Source/FastMathFunctions/arm_sin_q31.o \
./src/Source/FastMathFunctions/arm_sqrt_q15.o \
./src/Source/FastMathFunctions/arm_sqrt_q31.o 

C_DEPS += \
./src/Source/FastMathFunctions/arm_cos_f32.d \
./src/Source/FastMathFunctions/arm_cos_q15.d \
./src/Source/FastMathFunctions/arm_cos_q31.d \
./src/Source/FastMathFunctions/arm_sin_f32.d \
./src/Source/FastMathFunctions/arm_sin_q15.d \
./src/Source/FastMathFunctions/arm_sin_q31.d \
./src/Source/FastMathFunctions/arm_sqrt_q15.d \
./src/Source/FastMathFunctions/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
src/Source/FastMathFunctions/%.o: ../src/Source/FastMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F4DISCOVERY -DDEBUG -DSTM32F40XX -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -DARM_MATH_CM4 -I"C:/Users/Bartolomeo/Desktop/pawlosz/Utilities" -I"C:/Users/Bartolomeo/Desktop/pawlosz/StdPeriph_Driver/inc" -I"C:/Users/Bartolomeo/Desktop/pawlosz/inc" -I"C:/Users/Bartolomeo/Desktop/pawlosz/CMSIS/device" -I"C:/Users/Bartolomeo/Desktop/pawlosz/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


