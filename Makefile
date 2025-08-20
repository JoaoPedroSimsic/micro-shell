CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -Iinclude

SRCDIR = src
INCDIR = include
BUILDDIR = build

$(shell mkdir -p $(BUILDDIR))

TARGET = $(BUILDDIR)/TRASH

SRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) 

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

.PHONY: all run clean

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
	rmdir $(BUILDDIR) 2>/dev/null || true 

