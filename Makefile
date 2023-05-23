# Compiler options
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic -Werror

# Linker options
LDFLAGS = -L ./libs -lSDL2 -lSDL2_mixer -lSDL2_ttf

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./include

# Files
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INCLUDES = -I $(INC_DIR)

# Exec
EXEC = $(BIN_DIR)/pacman

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -o $@ $(LDFLAGS) $(CXXFLAGS) $(INCLUDES) -c $<

see:
	@echo $(OBJS)

clean:
	rm -f $(OBJ_DIR)/* $(BIN_DIR)/* && clear

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all clean
