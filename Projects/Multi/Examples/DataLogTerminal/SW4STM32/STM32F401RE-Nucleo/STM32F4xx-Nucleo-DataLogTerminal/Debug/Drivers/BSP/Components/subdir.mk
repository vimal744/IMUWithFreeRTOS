################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221/HTS221_Driver.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221/HTS221_Driver_HL.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl/LIS3MDL_MAG_driver.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl/LIS3MDL_MAG_driver_HL.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb/LPS22HB_Driver.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb/LPS22HB_Driver_HL.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb/LPS25HB_Driver.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb/LPS25HB_Driver_HL.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0/LSM6DS0_ACC_GYRO_driver.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0/LSM6DS0_ACC_GYRO_driver_HL.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3/LSM6DS3_ACC_GYRO_driver.c \
C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3/LSM6DS3_ACC_GYRO_driver_HL.c 

OBJS += \
./Drivers/BSP/Components/HTS221_Driver.o \
./Drivers/BSP/Components/HTS221_Driver_HL.o \
./Drivers/BSP/Components/LIS3MDL_MAG_driver.o \
./Drivers/BSP/Components/LIS3MDL_MAG_driver_HL.o \
./Drivers/BSP/Components/LPS22HB_Driver.o \
./Drivers/BSP/Components/LPS22HB_Driver_HL.o \
./Drivers/BSP/Components/LPS25HB_Driver.o \
./Drivers/BSP/Components/LPS25HB_Driver_HL.o \
./Drivers/BSP/Components/LSM6DS0_ACC_GYRO_driver.o \
./Drivers/BSP/Components/LSM6DS0_ACC_GYRO_driver_HL.o \
./Drivers/BSP/Components/LSM6DS3_ACC_GYRO_driver.o \
./Drivers/BSP/Components/LSM6DS3_ACC_GYRO_driver_HL.o 

C_DEPS += \
./Drivers/BSP/Components/HTS221_Driver.d \
./Drivers/BSP/Components/HTS221_Driver_HL.d \
./Drivers/BSP/Components/LIS3MDL_MAG_driver.d \
./Drivers/BSP/Components/LIS3MDL_MAG_driver_HL.d \
./Drivers/BSP/Components/LPS22HB_Driver.d \
./Drivers/BSP/Components/LPS22HB_Driver_HL.d \
./Drivers/BSP/Components/LPS25HB_Driver.d \
./Drivers/BSP/Components/LPS25HB_Driver_HL.d \
./Drivers/BSP/Components/LSM6DS0_ACC_GYRO_driver.d \
./Drivers/BSP/Components/LSM6DS0_ACC_GYRO_driver_HL.d \
./Drivers/BSP/Components/LSM6DS3_ACC_GYRO_driver.d \
./Drivers/BSP/Components/LSM6DS3_ACC_GYRO_driver_HL.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/HTS221_Driver.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221/HTS221_Driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/HTS221_Driver_HL.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221/HTS221_Driver_HL.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LIS3MDL_MAG_driver.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl/LIS3MDL_MAG_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LIS3MDL_MAG_driver_HL.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl/LIS3MDL_MAG_driver_HL.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LPS22HB_Driver.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb/LPS22HB_Driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LPS22HB_Driver_HL.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb/LPS22HB_Driver_HL.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LPS25HB_Driver.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb/LPS25HB_Driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LPS25HB_Driver_HL.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb/LPS25HB_Driver_HL.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LSM6DS0_ACC_GYRO_driver.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0/LSM6DS0_ACC_GYRO_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LSM6DS0_ACC_GYRO_driver_HL.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0/LSM6DS0_ACC_GYRO_driver_HL.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LSM6DS3_ACC_GYRO_driver.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3/LSM6DS3_ACC_GYRO_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/Components/LSM6DS3_ACC_GYRO_driver_HL.o: C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3/LSM6DS3_ACC_GYRO_driver_HL.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -DUSE_STM32F4XX_NUCLEO -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Projects/Multi/Examples/DataLogTerminal/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/STM32F4xx-Nucleo" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/CMSIS/Include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/X_NUCLEO_IKS01A1" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/Common" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/hts221" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lis3mdl" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps25hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds0" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lsm6ds3" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Drivers/BSP/Components/lps22hb" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/mehta/Documents/GitHub/IMUWithFreeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


