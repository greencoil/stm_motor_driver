################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/stm32f3xx_hal_msp.c \
../Src/stm32f3xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f3xx.c 

CPP_SRCS += \
../Src/main.cpp \
../Src/mainpp.cpp 

OBJS += \
./Src/main.o \
./Src/mainpp.o \
./Src/stm32f3xx_hal_msp.o \
./Src/stm32f3xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f3xx.o 

C_DEPS += \
./Src/stm32f3xx_hal_msp.d \
./Src/stm32f3xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f3xx.d 

CPP_DEPS += \
./Src/main.d \
./Src/mainpp.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Inc" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/CMSIS/Include"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Inc" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/home/yamaguchi/prog/stm32/ros_test/chatter/Drivers/CMSIS/Include"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


