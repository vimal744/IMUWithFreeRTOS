################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/PrintUtility.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/SensorApplicationMain.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/SensorFusionMain.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/SensorReaderMain.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/UartInterface.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/com.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/cube_hal_f4.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/freertos.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/main.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/stm32f4xx_hal_msp.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/stm32f4xx_hal_timebase_TIM.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/stm32f4xx_it.c 

OBJS += \
./Example/User/Src/PrintUtility.o \
./Example/User/Src/SensorApplicationMain.o \
./Example/User/Src/SensorFusionMain.o \
./Example/User/Src/SensorReaderMain.o \
./Example/User/Src/UartInterface.o \
./Example/User/Src/com.o \
./Example/User/Src/cube_hal_f4.o \
./Example/User/Src/freertos.o \
./Example/User/Src/main.o \
./Example/User/Src/stm32f4xx_hal_msp.o \
./Example/User/Src/stm32f4xx_hal_timebase_TIM.o \
./Example/User/Src/stm32f4xx_it.o 

C_DEPS += \
./Example/User/Src/PrintUtility.d \
./Example/User/Src/SensorApplicationMain.d \
./Example/User/Src/SensorFusionMain.d \
./Example/User/Src/SensorReaderMain.d \
./Example/User/Src/UartInterface.d \
./Example/User/Src/com.d \
./Example/User/Src/cube_hal_f4.d \
./Example/User/Src/freertos.d \
./Example/User/Src/main.d \
./Example/User/Src/stm32f4xx_hal_msp.d \
./Example/User/Src/stm32f4xx_hal_timebase_TIM.d \
./Example/User/Src/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Example/User/Src/PrintUtility.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/PrintUtility.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/SensorApplicationMain.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/SensorApplicationMain.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/SensorFusionMain.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/SensorFusionMain.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/SensorReaderMain.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/SensorReaderMain.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/UartInterface.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/UartInterface.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/com.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/com.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/cube_hal_f4.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/cube_hal_f4.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/freertos.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/freertos.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/main.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/stm32f4xx_hal_msp.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/stm32f4xx_hal_timebase_TIM.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/stm32f4xx_hal_timebase_TIM.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example/User/Src/stm32f4xx_it.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


