################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Projects/Multi/Examples/DataLogTerminal/Src/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Projects/Multi/Examples/DataLogTerminal/Src/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/CMSIS/Include" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/Common" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/workspace/STM32/SensorFusion_Final_2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


