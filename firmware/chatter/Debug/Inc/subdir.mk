################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Inc/duration.cpp \
../Inc/time.cpp 

OBJS += \
./Inc/duration.o \
./Inc/time.o 

CPP_DEPS += \
./Inc/duration.d \
./Inc/time.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Inc" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/CMSIS/Include"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


