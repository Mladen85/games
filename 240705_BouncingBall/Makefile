# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
LDFLAGS := -lX11 -lGL -lpthread -lpng -lstdc++fs

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
LIB_DIR := lib

# Source files (add your own .cpp files here)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# olcPixelGameEngine library settings
OLC_ENGINE := lib/olcPixelGameEngine.o
OLC_INCLUDE := -Ilib

# Phony targets
.PHONY: all clean


# Target executable
TARGET := $(BIN_DIR)/game

# Main target
$(TARGET): $(OBJS) $(OLC_ENGINE)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# Compile each .cpp file into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(OLC_INCLUDE) -c $< -o $@

# Build olcPixelGameEngine as a library
$(OLC_ENGINE):
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)


