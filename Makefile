CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c
OBJ = $(SRC:.c=.o)

TARGET = mysh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./mysh

clean: 
	rm -f $(OBJ) $(TARGET)
