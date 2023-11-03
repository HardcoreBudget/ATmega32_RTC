################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/Source/subdir.mk
-include MCAL/TMR2/Source/subdir.mk
-include MCAL/TMR1/Source/subdir.mk
-include MCAL/TMR0/Source/subdir.mk
-include MCAL/SPI/Source/subdir.mk
-include MCAL/I2C/Source/subdir.mk
-include MCAL/GIE/Source/subdir.mk
-include MCAL/EXTI/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/Source/subdir.mk
-include HAL/SevSeg/Source/subdir.mk
-include HAL/LCD/Source/subdir.mk
-include HAL/Keypad/Source/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
RTC.lss \

FLASH_IMAGE += \
RTC.hex \

EEPROM_IMAGE += \
RTC.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: RTC.elf secondary-outputs

# Tool invocations
RTC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,RTC.map -mmcu=atmega32 -o "RTC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RTC.lss: RTC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S RTC.elf  >"RTC.lss"
	@echo 'Finished building: $@'
	@echo ' '

RTC.hex: RTC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex RTC.elf  "RTC.hex"
	@echo 'Finished building: $@'
	@echo ' '

RTC.eep: RTC.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex RTC.elf  "RTC.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RTC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 RTC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) RTC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
