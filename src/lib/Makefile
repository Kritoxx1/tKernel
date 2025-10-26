# Lib/Makefile

CC = gcc
CFLAGS = -m32 -ffreestanding -fno-stack-protector -O2 -Wall -Wextra -I.

SRC = std.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: rm -f $(OBJ)
