CC = gcc
CFLAGS = -Wall -Werror -g -I./utils/include -I./include
LDFLAGS = 
SOURCES = src/main.c utils/src/linkedlist.c src/hash_table.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean