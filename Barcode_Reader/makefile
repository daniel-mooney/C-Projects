CC=gcc
CFLAGS=-g -Wall -std=c99
LIBS= -lm
TARGET=barcode_reader

DEPS = bitmap.h functions.h
OBJS = main.o bitmap.o functions.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
