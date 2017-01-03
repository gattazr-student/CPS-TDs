# Makefile
CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=ex1 ex2 ex3 ex4 ex5 ex6 ex7

all: $(EXEC)

# Cleaning rules
clean: mrproper
	rm -f $(foreach exec, $(EXEC), $(addprefix $(exec),.o))

mrproper:
	rm -f $(EXEC)

.PHONY: all clean mrproper
