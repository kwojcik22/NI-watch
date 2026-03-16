################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/bsp/RTC/Time.c 

OBJS += \
./Core/Inc/bsp/RTC/Time.o 

C_DEPS += \
./Core/Inc/bsp/RTC/Time.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/bsp/RTC/%.o Core/Inc/bsp/RTC/%.su Core/Inc/bsp/RTC/%.cyclo: ../Core/Inc/bsp/RTC/%.c Core/Inc/bsp/RTC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-bsp-2f-RTC

clean-Core-2f-Inc-2f-bsp-2f-RTC:
	-$(RM) ./Core/Inc/bsp/RTC/Time.cyclo ./Core/Inc/bsp/RTC/Time.d ./Core/Inc/bsp/RTC/Time.o ./Core/Inc/bsp/RTC/Time.su

.PHONY: clean-Core-2f-Inc-2f-bsp-2f-RTC

