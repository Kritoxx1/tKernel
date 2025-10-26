
# ===== Toolchain setup =====
CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)nasm

# ===== Build flags =====
CFLAGS = -m32 -ffreestanding -O2 -fno-builtin -fno-stack-protector -Wall -Wextra
LDFLAGS = -m elf_i386

# ===== Sources =====
BOOT_SRC = src/boot/boot.s
KERNEL_SRC = src/kernel/kernel.c
LINKER_SCRIPT = src/linker.ld

OBJS = build/boot.o build/kernel.o build/std.o

# ===== Default target =====
all: os.iso

# ===== Build rules =====
build/std.o:
	$(MAKE) -C src/lib
	mv src/lib/std.o build/std.o

build/boot.o: $(BOOT_SRC)
	mkdir -p build
	$(AS) -f elf32 $(BOOT_SRC) -o $@

build/kernel.o: $(KERNEL_SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -c $(KERNEL_SRC) -o $@

build/kernel.elf: $(OBJS) $(LINKER_SCRIPT)
	$(LD) $(LDFLAGS) -T $(LINKER_SCRIPT) -o build/kernel.elf $(OBJS)

iso/boot/kernel.elf: build/kernel.elf
	mkdir -p iso/boot/grub
	cp build/kernel.elf iso/boot/
	cp grub.cfg iso/boot/grub/

os.iso: iso/boot/kernel.elf
	grub-mkrescue -o os.iso iso

run: os.iso
	qemu-system-i386 -cdrom os.iso -m 512

clean:
	rm -rf build iso os.iso

