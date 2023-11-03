################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/I2C/Source/I2C_Imp.c 

OBJS += \
./MCAL/I2C/Source/I2C_Imp.o 

C_DEPS += \
./MCAL/I2C/Source/I2C_Imp.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/I2C/Source/%.o: ../MCAL/I2C/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


