# Compiler
CXX = x86_64-w64-mingw32-g++
RayLib = ./Raylib

# Windows deployment
CXXFLAGS = -std=c++20 -Wall -g -I$(RayLib)/include -I./libpacman/include -static-libstdc++ -static-libgcc -O2 -DNDEBUG
LDFLAGS  = -L$(RayLib)/lib -L./libpacman -lraylib -lpacman -lopengl32 -lgdi32 -lwinmm -mconsole #-mwindows

# Files & directories
SRCS := $(wildcard src/*.cpp)   # Only the LevelEditor sources
BUILD_DIR := build
OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
TARGET = LevelEditor

# Default rule
all: $(TARGET)

# Ensure build directory exists
$(BUILD_DIR):
ifeq ($(IS_WINDOWS),1)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif

# Build app, linking with libpacman.a
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Compile .cpp to .o (in build dir)
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
ifeq ($(OS),Windows_NT)
	-rmdir /s /q $(BUILD_DIR)
	-del $(TARGET)
else
	rm -rf $(BUILD_DIR) $(TARGET)
endif
