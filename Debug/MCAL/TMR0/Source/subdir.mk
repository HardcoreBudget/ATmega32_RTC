################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TMR0/Source/TMR0_Imp.c 

OBJS += \
./MCAL/TMR0/Source/TMR0_Imp.o 

C_DEPS += \
./MCAL/TMR0/Source/TMR0_Imp.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TMR0/Source/%.o: ../MCAL/TMR0/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


