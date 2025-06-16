# Configuración para Linux ARM
ARM_CC = arm-linux-gnueabihf-gcc
CFLAGS = -I. -I./drivers -I./audio -Wall -Os -ffunction-sections -fdata-sections
LDFLAGS = -static -lm -Wl,--gc-sections

CORE_SRC = src/main.c src/state_machine.c src/playlist.c src/ui.c \
           audio/decoder.c audio/audio_controller.c \
           drivers/interrupts.c drivers/hardware_interface.c

HW_SRC = drivers/hardware_real.c drivers/sd_card.c drivers/minimal_io.c

OUT_PROD = build/audio_player

# Usar variable para el directorio de montaje
SD_MOUNT = /media/$(USER)/rootfs/root

prod: $(CORE_SRC) $(HW_SRC)
	$(ARM_CC) $(CFLAGS) $^ -o $(OUT_PROD) $(LDFLAGS)
	@echo "--------------------------------------------------"
	@echo "¡Ejecutable generado con éxito!: $(OUT_PROD)"
	@echo "Tamaño: `ls -lh $(OUT_PROD) | awk '{print $$5}'`"
	@echo "Para copiar a la uSD:"
	@echo "sudo cp $(OUT_PROD) $(SD_MOUNT)/"
	@echo "--------------------------------------------------"

install:
	@if [ -d "$(SD_MOUNT)" ]; then \
		sudo cp $(OUT_PROD) $(SD_MOUNT)/; \
		echo "¡Binario copiado a la uSD!"; \
	else \
		echo "¡Error! Directorio no encontrado: $(SD_MOUNT)"; \
		echo "Por favor monte la uSD manualmente"; \
	fi

clean:
	rm -f $(OUT_PROD) build/*

.PHONY: prod clean install
