CC = gcc
CFLAGS = -std=c17 -g -Wall -Wextra -fno-common
TARGETS = $(patsubst %.c,%.exe,$(wildcard *.c)) test06-1/main.exe

.PHONY: all clean scope-error linkage-error

all: $(TARGETS)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

test06-1/main.exe: test06-1/main.c test06-1/sub.c
	$(CC) $(CFLAGS) $^ -o $@

# These two targets intentionally fail to demonstrate the assignment errors.
scope-error:
	$(CC) $(CFLAGS) test01-before/main.c -o test01-before/main.exe

linkage-error:
	$(CC) $(CFLAGS) test06-2/main.c test06-2/sum.c -o test06-2/main.exe

clean:
	rm -f $(TARGETS)
