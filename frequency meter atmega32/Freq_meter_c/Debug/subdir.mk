################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../GLOBAL_INTERRUPT_program.c \
../LCD_program.c \
../TIMER_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./GLOBAL_INTERRUPT_program.o \
./LCD_program.o \
./TIMER_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./GLOBAL_INTERRUPT_program.d \
./LCD_program.d \
./TIMER_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=11059200UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

