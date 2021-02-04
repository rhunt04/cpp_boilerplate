CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
ARCH     := $(shell uname -m)

BUILD    := ./build-$(ARCH)
OBJ_DIR  := $(BUILD)/obj
APP_DIR  := $(BUILD)/bin

INCLUDE  := -Isrc/classes/
TARGET   := main
SRC      := $(wildcard src/*.cpp src/classes/*.cpp)
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# TODO: Use these?
#DBG_BUILD   := ./build-$(ARCH)-dbg
#DBG_OBJ_DIR := $(DBG_BUILD)/obj
#DBG_APP_DIR := $(DBG_BUILD)/bin
#DBG_OBJECTS := $(SRC:%.cpp=$(DBG_OBJ_DIR)/%.o)

#REL_BUILD   := ./build-$(ARCH)-rel
#REL_OBJ_DIR := $(REL_BUILD)/obj
#REL_APP_DIR := $(REL_BUILD)/bin
#REL_OBJECTS := $(SRC:%.cpp=$(REL_OBJ_DIR)/%.o)

# TODO: sensible scheme for colouring.
cRED=$(shell echo "\033[0;31m")
cGRE=$(shell echo "\033[0;32m")
cYEL=$(shell echo "\033[0;33m")
c=$(shell echo "\033[0m")

.PHONY: all clean debug release vclean remake

all: $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@echo "[O] Making $@ from $< in $(@D)."
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)
	@echo -n "$(c)"

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@echo "[T] Making $@ from $< in $(@D)."
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)
	@echo -n "$(c)"

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

vclean:
	-@rm -rvf $(BUILD)

remake: vclean all
