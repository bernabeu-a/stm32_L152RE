CC = /opt/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc
MACH = cortex-m3
STL = st-flash
BIN = /opt/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-objcopy
DEBUG = /opt/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb
CFLAGS = -c -mthumb -mcpu=$(MACH) -std=gnu11 -O0 -Wall -g
LDFLAGS = -T stm32_ls.ld -nostdlib -Wl,-Map=main.map

all: main.bin

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

main.elf: main.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

main.bin: main.elf
	$(BIN) -O binary main.elf main.bin

flash: main.bin
	$(STL) write main.bin 0x8000000

clean:
	rm -rf *.o *.elf *.bin *.map

debug:
	$(DEBUG) -tui main.elf