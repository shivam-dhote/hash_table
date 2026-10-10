CC = gcc
AR = ar
RANLIB = ranlib
CFLAGS = -Wall -Werror -g -I./utils/include -I./include
LDFLAGS = 

# Sources
LIB_SOURCES = src/hash_table.c utils/src/linkedlist.c
APP_SOURCES = src/main.c src/user.c

OBJ_DIR = build
LIB_DIR = $(OBJ_DIR)/lib
BIN_DIR = $(OBJ_DIR)/out

LIB_OBJECTS = $(LIB_SOURCES:%.c=$(OBJ_DIR)/%.o)
APP_OBJECTS = $(APP_SOURCES:%.c=$(OBJ_DIR)/%.o)

LIB = $(LIB_DIR)/libhash_table.a
TARGET = $(BIN_DIR)/main

# platform-specific prebuilt directory
PLATFORM := $(shell uname -s | tr '[:upper:]' '[:lower:]')
PREBUILT_DIR := prebuilt/$(PLATFORM)

lib-only: build_dir $(LIB)

prebuilt: lib-only
	@mkdir -p $(PREBUILT_DIR)
	cp -f $(LIB) $(PREBUILT_DIR)/libhash_table.a
	@echo "Copied $(LIB) -> $(PREBUILT_DIR)/libhash_table.a"

all: lib-only

build_dir:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(dir $(LIB_OBJECTS)) $(dir $(APP_OBJECTS)) $(LIB_DIR)

$(LIB): $(LIB_OBJECTS)
	$(AR) rcs $(LIB) $(LIB_OBJECTS)
	-$(RANLIB) $(LIB)

$(TARGET): $(APP_OBJECTS) $(LIB)
	$(CC) $(CFLAGS) -o $(TARGET) $(APP_OBJECTS) -L$(LIB_DIR) -lhash_table $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build

distclean: clean
	rm -rf prebuilt

.PHONY: all clean distclean build_dir lib-only prebuilt