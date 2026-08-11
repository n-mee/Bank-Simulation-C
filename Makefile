CC := gcc
CFLAGS := -Iinclude -Wall -Wextra -g

BIN_DIR := bin
BUILD_DIR := build

SRCS := src/main.c $(wildcard src/cli/*.c src/repositories/*.c src/controllers/*.c src/services/*.c src/common/*.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

TARGET := $(BIN_DIR)/bankapp

.PHONY: all clean memcheck run

all: $(TARGET)

$(TARGET): $(OBJS)
		@mkdir -p $(BIN_DIR)
		$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

memcheck: $(TARGET)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         ./$(TARGET)

run: all
		./$(TARGET)

-include $(DEPS)