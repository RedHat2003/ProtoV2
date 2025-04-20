CC ?= gcc
CFLAGS += -I../include -Wall -Wextra -pedantic -std=c11
LDFLAGS += -L../build/object -L../build/hat -lobject_lib -lhat

all: test_core

test_core: test_core.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f test_core

.PHONY: all clean