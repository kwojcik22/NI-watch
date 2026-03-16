################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Manager/Flags.c \
../Core/Inc/Manager/manager.c 

OBJS += \
./Core/Inc/Manager/Flags.o \
./Core/Inc/Manager/manager.o 

C_DEPS += \
./Core/Inc/Manager/Flags.d \
./Core/Inc/Manager/manager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Manager/%.o Core/Inc/Manager/%.su Core/Inc/Manager/%.cyclo: ../Core/Inc/Manager/%.c Core/Inc/Manager/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Manager

clean-Core-2f-Inc-2f-Manager:
	-$(RM) ./Core/Inc/Manager/Flags.cyclo ./Core/Inc/Manager/Flags.d ./Core/Inc/Manager/Flags.o ./Core/Inc/Manager/Flags.su ./Core/Inc/Manager/manager.cyclo ./Core/Inc/Manager/manager.d ./Core/Inc/Manager/manager.o ./Core/Inc/Manager/manager.su

.PHONY: clean-Core-2f-Inc-2f-Manager

