CXX := g++
CXXFLAGS := -Iinclude -Wall -Wextra -g -MMD -MP

BIN_DIR := bin
BUILD_DIR := build

SRCS := src/main.cpp $(wildcard src/cli/*.cpp src/repositories/*.cpp src/controllers/*.cpp src/services/*.cpp src/common/*.cpp)
OBJS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

TARGET := $(BIN_DIR)/bankapp

.PHONY: all clean memcheck run

all: $(TARGET)

$(TARGET): $(OBJS)
		@mkdir -p $(BIN_DIR)
		$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
		@mkdir -p $(dir $@)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

memcheck: $(TARGET)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
			 --error-exitcode=1 \
	         ./$(TARGET)

run: all
		./$(TARGET)

-include $(DEPS)