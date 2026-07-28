CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -g

BIN_DIR := bin
BUILD_DIR := build

SRCS := src/main.c $(wildcard src/views/*.c src/auth/*.c src/controllers/*.c src/validation/*.c src/core/*.c src/utils/*.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

TARGET := $(BIN_DIR)/bankapp

all: $(TARGET)

$(TARGET): $(OBJS)
		@mkdir -p $(BIN_DIR)
		$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

run: all
		./$(TARGET)