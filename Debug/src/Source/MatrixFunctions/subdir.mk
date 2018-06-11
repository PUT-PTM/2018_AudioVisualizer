################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Source/MatrixFunctions/arm_mat_add_f32.c \
../src/Source/MatrixFunctions/arm_mat_add_q15.c \
../src/Source/MatrixFunctions/arm_mat_add_q31.c \
../src/Source/MatrixFunctions/arm_mat_init_f32.c \
../src/Source/MatrixFunctions/arm_mat_init_q15.c \
../src/Source/MatrixFunctions/arm_mat_init_q31.c \
../src/Source/MatrixFunctions/arm_mat_inverse_f32.c \
../src/Source/MatrixFunctions/arm_mat_mult_f32.c \
../src/Source/MatrixFunctions/arm_mat_mult_fast_q15.c \
../src/Source/MatrixFunctions/arm_mat_mult_fast_q31.c \
../src/Source/MatrixFunctions/arm_mat_mult_q15.c \
../src/Source/MatrixFunctions/arm_mat_mult_q31.c \
../src/Source/MatrixFunctions/arm_mat_scale_f32.c \
../src/Source/MatrixFunctions/arm_mat_scale_q15.c \
../src/Source/MatrixFunctions/arm_mat_scale_q31.c \
../src/Source/MatrixFunctions/arm_mat_sub_f32.c \
../src/Source/MatrixFunctions/arm_mat_sub_q15.c \
../src/Source/MatrixFunctions/arm_mat_sub_q31.c \
../src/Source/MatrixFunctions/arm_mat_trans_f32.c \
../src/Source/MatrixFunctions/arm_mat_trans_q15.c \
../src/Source/MatrixFunctions/arm_mat_trans_q31.c 

OBJS += \
./src/Source/MatrixFunctions/arm_mat_add_f32.o \
./src/Source/MatrixFunctions/arm_mat_add_q15.o \
./src/Source/MatrixFunctions/arm_mat_add_q31.o \
./src/Source/MatrixFunctions/arm_mat_init_f32.o \
./src/Source/MatrixFunctions/arm_mat_init_q15.o \
./src/Source/MatrixFunctions/arm_mat_init_q31.o \
./src/Source/MatrixFunctions/arm_mat_inverse_f32.o \
./src/Source/MatrixFunctions/arm_mat_mult_f32.o \
./src/Source/MatrixFunctions/arm_mat_mult_fast_q15.o \
./src/Source/MatrixFunctions/arm_mat_mult_fast_q31.o \
./src/Source/MatrixFunctions/arm_mat_mult_q15.o \
./src/Source/MatrixFunctions/arm_mat_mult_q31.o \
./src/Source/MatrixFunctions/arm_mat_scale_f32.o \
./src/Source/MatrixFunctions/arm_mat_scale_q15.o \
./src/Source/MatrixFunctions/arm_mat_scale_q31.o \
./src/Source/MatrixFunctions/arm_mat_sub_f32.o \
./src/Source/MatrixFunctions/arm_mat_sub_q15.o \
./src/Source/MatrixFunctions/arm_mat_sub_q31.o \
./src/Source/MatrixFunctions/arm_mat_trans_f32.o \
./src/Source/MatrixFunctions/arm_mat_trans_q15.o \
./src/Source/MatrixFunctions/arm_mat_trans_q31.o 

C_DEPS += \
./src/Source/MatrixFunctions/arm_mat_add_f32.d \
./src/Source/MatrixFunctions/arm_mat_add_q15.d \
./src/Source/MatrixFunctions/arm_mat_add_q31.d \
./src/Source/MatrixFunctions/arm_mat_init_f32.d \
./src/Source/MatrixFunctions/arm_mat_init_q15.d \
./src/Source/MatrixFunctions/arm_mat_init_q31.d \
./src/Source/MatrixFunctions/arm_mat_inverse_f32.d \
./src/Source/MatrixFunctions/arm_mat_mult_f32.d \
./src/Source/MatrixFunctions/arm_mat_mult_fast_q15.d \
./src/Source/MatrixFunctions/arm_mat_mult_fast_q31.d \
./src/Source/MatrixFunctions/arm_mat_mult_q15.d \
./src/Source/MatrixFunctions/arm_mat_mult_q31.d \
./src/Source/MatrixFunctions/arm_mat_scale_f32.d \
./src/Source/MatrixFunctions/arm_mat_scale_q15.d \
./src/Source/MatrixFunctions/arm_mat_scale_q31.d \
./src/Source/MatrixFunctions/arm_mat_sub_f32.d \
./src/Source/MatrixFunctions/arm_mat_sub_q15.d \
./src/Source/MatrixFunctions/arm_mat_sub_q31.d \
./src/Source/MatrixFunctions/arm_mat_trans_f32.d \
./src/Source/MatrixFunctions/arm_mat_trans_q15.d \
./src/Source/MatrixFunctions/arm_mat_trans_q31.d 


# Each subdirectory must supply rules for building sources it contributes
src/Source/MatrixFunctions/%.o: ../src/Source/MatrixFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F4DISCOVERY -DDEBUG -DSTM32F40XX -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -DARM_MATH_CM4 -I"C:/Users/Bartolomeo/Desktop/pawlosz/Utilities" -I"C:/Users/Bartolomeo/Desktop/pawlosz/StdPeriph_Driver/inc" -I"C:/Users/Bartolomeo/Desktop/pawlosz/inc" -I"C:/Users/Bartolomeo/Desktop/pawlosz/CMSIS/device" -I"C:/Users/Bartolomeo/Desktop/pawlosz/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


