# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
LDFLAGS := -lX11 -lGL -lpthread -lpng -lstdc++fs

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
LIB_DIR := lib
LIB_BUILD_DIR := $(LIB_DIR)/build

# Source files (add your own .cpp files here)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# olcPixelGameEngine library settings
OLC_ENGINE := $(LIB_BUILD_DIR)/libolc.a
OLC_INCLUDE := -I$(LIB_DIR)

# Phony targets
.PHONY: all clean clean_olc clean_all

# Target executable
TARGET := $(BIN_DIR)/game

# Main target
all: $(TARGET)

$(TARGET): $(OBJS) $(OLC_ENGINE)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OLC_ENGINE) $(LDFLAGS) -o $@

# Compile each .cpp file into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(OLC_INCLUDE) -c $< -o $@

# Build olcPixelGameEngine as a static library
$(OLC_ENGINE): $(LIB_DIR)/olcPixelGameEngine.cpp
	@mkdir -p $(LIB_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $(LIB_BUILD_DIR)/olcPixelGameEngine.o
	ar rcs $(OLC_ENGINE) $(LIB_BUILD_DIR)/olcPixelGameEngine.o

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Clean olcPixelGameEngine build
clean_olc:
	rm -rf $(LIB_BUILD_DIR)

# Combined clean
clean_all: clean clean_olc