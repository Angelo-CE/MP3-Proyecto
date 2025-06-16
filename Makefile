# Configuración para SoC EDS
SOCEDS_PATH = $(HOME)/intelFPGA/18.1/embedded/host_tools/mentor/gnu/arm/baremetal
ARM_CC = $(SOCEDS_PATH)/bin/arm-altera-eabi-gcc
OBJCOPY = $(SOCEDS_PATH)/bin/arm-altera-eabi-objcopy

# Flags de compilación
CFLAGS = -I. -I./drivers -I./audio -g -Wall -mcpu=cortex-a9 -mfloat-abi=soft -ffreestanding -nostdlib -Os
LDFLAGS = -T linker.ld -static -nostdlib -Wl,-u,main -Wl,--gc-sections -lgcc

# Fuentes principales
CORE_SRC = src/main.c src/state_machine.c src/playlist.c src/ui.c
AUDIO_SRC = audio/audio_controller.c audio/decoder.c
DRIVER_SRC = drivers/interrupts.c drivers/hardware_interface.c drivers/minimal_io.c drivers/syscalls.c drivers/sd_card.c
STARTUP_SRC = startup.s

OBJS = $(CORE_SRC:.c=.o) $(AUDIO_SRC:.c=.o) $(DRIVER_SRC:.c=.o) $(STARTUP_SRC:.s=.o)

OUT_PROD = build/audio_player.elf
OUT_BIN = build/audio_player.bin

# Reglas principales
all: $(OUT_BIN)

$(OUT_BIN): $(OUT_PROD)
	$(OBJCOPY) -O binary $< $@
	@echo "Binario generado: $(OUT_BIN)"

$(OUT_PROD): $(OBJS)
	$(ARM_CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Reglas de compilación
%.o: %.c
	$(ARM_CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(ARM_CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OUT_PROD) $(OUT_BIN) $(OBJS)

# Instalación
install: $(OUT_BIN)
	@echo "Copiando a tarjeta SD..."
	@if [ -d "/media/$(USER)/BOOT" ]; then \
		sudo cp $(OUT_BIN) /media/$(USER)/BOOT/; \
		echo "Copiado a /media/$(USER)/BOOT/"; \
	else \
		echo "No se encontró la tarjeta SD montada"; \
	fi

# Simulación
sim:
	gcc -DSIMULATOR -I. -I./drivers -I./audio \
		src/main.c src/state_machine.c src/playlist.c src/ui.c \
		audio/audio_controller.c audio/decoder.c \
		drivers/interrupts.c drivers/hardware_interface.c drivers/minimal_io.c drivers/syscalls.c drivers/sd_card.c \
		-o build/audio_sim -lm

.PHONY: all clean install sim
