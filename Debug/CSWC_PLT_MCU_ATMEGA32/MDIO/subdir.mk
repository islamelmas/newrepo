################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CSWC_PLT_MCU_ATMEGA32/MDIO/MDIO_prg.c 

OBJS += \
./CSWC_PLT_MCU_ATMEGA32/MDIO/MDIO_prg.o 

C_DEPS += \
./CSWC_PLT_MCU_ATMEGA32/MDIO/MDIO_prg.d 


# Each subdirectory must supply rules for building sources it contributes
CSWC_PLT_MCU_ATMEGA32/MDIO/%.o: ../CSWC_PLT_MCU_ATMEGA32/MDIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


