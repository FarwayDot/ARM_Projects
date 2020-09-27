################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
Clase2_Ejemplo.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Clase2_Ejemplo.list \

OBJCOPY_BIN += \
Clase2_Ejemplo.bin \


# All Target
all: Clase2_Ejemplo.elf secondary-outputs

# Tool invocations
Clase2_Ejemplo.elf: $(OBJS) $(USER_OBJS) C:\Users\USER\Documents\ARM_Projects\Clase2_Ejemplo\STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "Clase2_Ejemplo.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\USER\Documents\ARM_Projects\Clase2_Ejemplo\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Clase2_Ejemplo.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Clase2_Ejemplo.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Clase2_Ejemplo.list"
	@echo 'Finished building: $@'
	@echo ' '

Clase2_Ejemplo.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Clase2_Ejemplo.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
