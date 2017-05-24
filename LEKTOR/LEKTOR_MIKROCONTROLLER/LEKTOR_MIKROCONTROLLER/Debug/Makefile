################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c \
../Manchester.c \
../RegistrerLektor_Optaget.c \
../RegistrerLektor_PaaKontor.c \
../SendOgModtag.c \
../Sensor.c \
../Timer.c \
../Timer_2.c \
../ToggleSwitch.c \
../ToggleSwitchLED.c \
../uart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
Manchester.o \
RegistrerLektor_Optaget.o \
RegistrerLektor_PaaKontor.o \
SendOgModtag.o \
Sensor.o \
Timer.o \
Timer_2.o \
ToggleSwitch.o \
ToggleSwitchLED.o \
uart.o

OBJS_AS_ARGS +=  \
main.o \
Manchester.o \
RegistrerLektor_Optaget.o \
RegistrerLektor_PaaKontor.o \
SendOgModtag.o \
Sensor.o \
Timer.o \
Timer_2.o \
ToggleSwitch.o \
ToggleSwitchLED.o \
uart.o

C_DEPS +=  \
main.d \
Manchester.d \
RegistrerLektor_Optaget.d \
RegistrerLektor_PaaKontor.d \
SendOgModtag.d \
Sensor.d \
Timer.d \
Timer_2.d \
ToggleSwitch.d \
ToggleSwitchLED.d \
uart.d

C_DEPS_AS_ARGS +=  \
main.d \
Manchester.d \
RegistrerLektor_Optaget.d \
RegistrerLektor_PaaKontor.d \
SendOgModtag.d \
Sensor.d \
Timer.d \
Timer_2.d \
ToggleSwitch.d \
ToggleSwitchLED.d \
uart.d

OUTPUT_FILE_PATH +=LEKTOR_MIKROCONTROLLER.elf

OUTPUT_FILE_PATH_AS_ARGS +=LEKTOR_MIKROCONTROLLER.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler























./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega2560" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LEKTOR_MIKROCONTROLLER.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega2560"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LEKTOR_MIKROCONTROLLER.elf" "LEKTOR_MIKROCONTROLLER.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LEKTOR_MIKROCONTROLLER.elf" "LEKTOR_MIKROCONTROLLER.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LEKTOR_MIKROCONTROLLER.elf" > "LEKTOR_MIKROCONTROLLER.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "LEKTOR_MIKROCONTROLLER.elf" "LEKTOR_MIKROCONTROLLER.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "LEKTOR_MIKROCONTROLLER.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LEKTOR_MIKROCONTROLLER.elf" "LEKTOR_MIKROCONTROLLER.a" "LEKTOR_MIKROCONTROLLER.hex" "LEKTOR_MIKROCONTROLLER.lss" "LEKTOR_MIKROCONTROLLER.eep" "LEKTOR_MIKROCONTROLLER.map" "LEKTOR_MIKROCONTROLLER.srec" "LEKTOR_MIKROCONTROLLER.usersignatures"
	