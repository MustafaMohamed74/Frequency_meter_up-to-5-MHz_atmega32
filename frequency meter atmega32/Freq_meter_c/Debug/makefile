################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Freq_meter_c.lss \

FLASH_IMAGE += \
Freq_meter_c.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Freq_meter_c.elf secondary-outputs

# Tool invocations
Freq_meter_c.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Freq_meter_c.map -mmcu=atmega32 -o "Freq_meter_c.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Freq_meter_c.lss: Freq_meter_c.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Freq_meter_c.elf  >"Freq_meter_c.lss"
	@echo 'Finished building: $@'
	@echo ' '

Freq_meter_c.hex: Freq_meter_c.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Freq_meter_c.elf  "Freq_meter_c.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Freq_meter_c.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Freq_meter_c.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Freq_meter_c.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Freq_meter_c.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Freq_meter_c.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
