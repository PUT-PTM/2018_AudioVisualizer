################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/Source/TransformFunctions/subdir.mk
-include src/Source/SupportFunctions/subdir.mk
-include src/Source/StatisticsFunctions/subdir.mk
-include src/Source/MatrixFunctions/subdir.mk
-include src/Source/FilteringFunctions/subdir.mk
-include src/Source/FastMathFunctions/subdir.mk
-include src/Source/ControllerFunctions/subdir.mk
-include src/Source/ComplexMathFunctions/subdir.mk
-include src/Source/CommonTables/subdir.mk
-include src/Source/BasicMathFunctions/subdir.mk
-include src/subdir.mk
-include Utilities/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pawlosz.elf

# Tool invocations
pawlosz.elf: $(OBJS) $(USER_OBJS) C:\Users\Bartolomeo\Desktop\pawlosz\LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -T"C:\Users\Bartolomeo\Desktop\pawlosz\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "pawlosz.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "pawlosz.elf" "pawlosz.bin"
	arm-none-eabi-size "pawlosz.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
