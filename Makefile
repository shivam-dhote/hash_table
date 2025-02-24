CC = gcc
CFLAGS = -Wall -Werror -g -I./utils/include -I./include
LDFLAGS = 
SOURCES = src/main.c utils/src/linkedlist.c src/hash_table.c
OBJECTS = $(SOURCES:%.c=build/%.o)
TARGET = build/out/main

all: build_dir $(TARGET)

build_dir:
	mkdir -p build build/out build/src build/utils/src

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

build/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean build_dir