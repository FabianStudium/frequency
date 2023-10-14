# Makefile for factor

# Compiler to use
CC = gcc

# Flags to pass compiler
CFLAGS = -Wall -std=c11

# Name for executable
EXE = frequency

# Space-separated list of source files
SOURCES = main.c frequency.c

# gcc -o gcd_program gcd.c factor.c -lm

# Automatically generated list of object files
OBJS = $(SOURCES:.c=.o)

# Default target
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

# Dependencies
main.o: main.c main.h
frequency.o: frequency.c frequency.h

# Housekeeping
clean:
	rm -f core $(EXE) $(OBJS)
