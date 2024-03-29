################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DET.c \
../Src/GPIO_lcfg.c \
../Src/GPIO_program.c \
../Src/RCC_program.c \
../Src/UART_program.c \
../Src/WIFI_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DET.o \
./Src/GPIO_lcfg.o \
./Src/GPIO_program.o \
./Src/RCC_program.o \
./Src/UART_program.o \
./Src/WIFI_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DET.d \
./Src/GPIO_lcfg.d \
./Src/GPIO_program.d \
./Src/RCC_program.d \
./Src/UART_program.d \
./Src/WIFI_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DET.cyclo ./Src/DET.d ./Src/DET.o ./Src/DET.su ./Src/GPIO_lcfg.cyclo ./Src/GPIO_lcfg.d ./Src/GPIO_lcfg.o ./Src/GPIO_lcfg.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/UART_program.cyclo ./Src/UART_program.d ./Src/UART_program.o ./Src/UART_program.su ./Src/WIFI_program.cyclo ./Src/WIFI_program.d ./Src/WIFI_program.o ./Src/WIFI_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

