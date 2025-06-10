CC = gcc
CFLAGS = -I. -I./drivers -I./audio -g -Wall
LDFLAGS = -lm -lpthread

CORE_SRC = src/main.c src/state_machine.c src/playlist.c src/ui.c \
           audio/decoder.c audio/audio_controller.c \
           drivers/interrupts.c drivers/hardware_interface.c

SIM_SRC = drivers/simulator.c
HW_SRC = drivers/hardware_real.c drivers/sd_card.c

OUT = build/audio_player

sim: $(CORE_SRC) $(SIM_SRC)
	$(CC) $(CFLAGS) $^ -o $(OUT) -DSIMULATOR=1 $(LDFLAGS)

prod: $(CORE_SRC) $(HW_SRC)
	$(CC) $(CFLAGS) $^ -o $(OUT) $(LDFLAGS)

run:
	./$(OUT)

clean:
	rm -f $(OUT)

.PHONY: sim prod run clean
