################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/bsp/PVD.c \
../Core/Inc/bsp/buttons.c 

OBJS += \
./Core/Inc/bsp/PVD.o \
./Core/Inc/bsp/buttons.o 

C_DEPS += \
./Core/Inc/bsp/PVD.d \
./Core/Inc/bsp/buttons.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/bsp/%.o Core/Inc/bsp/%.su Core/Inc/bsp/%.cyclo: ../Core/Inc/bsp/%.c Core/Inc/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-bsp

clean-Core-2f-Inc-2f-bsp:
	-$(RM) ./Core/Inc/bsp/PVD.cyclo ./Core/Inc/bsp/PVD.d ./Core/Inc/bsp/PVD.o ./Core/Inc/bsp/PVD.su ./Core/Inc/bsp/buttons.cyclo ./Core/Inc/bsp/buttons.d ./Core/Inc/bsp/buttons.o ./Core/Inc/bsp/buttons.su

.PHONY: clean-Core-2f-Inc-2f-bsp

