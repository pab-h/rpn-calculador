
CC = gcc
CFLAGS = -Wall

SRC_DIR = src
OUT_DIR = out

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OUTPUT = $(OUT_DIR)/main

all: $(OUTPUT)

$(OUTPUT): $(SRC_FILES) main.c
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $(SRC_FILES) main.c -o $(OUTPUT)

clean:
	rm -rf $(OUT_DIR)

.PHONY: all run clean
