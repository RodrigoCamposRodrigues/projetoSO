# Usage:
# make        # compile all binaries
# make clean  # remove all binaries, objects and pipes

CC=gcc
CFLAGS=-Wall 



SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

tokenring:
	@$(CC) tokenring.c $(CFLAGS) -o tokenring

clean:
		@echo "Cleaning up.."
		rm -rvf *.o ${BINS}
		find  . -name 'pipe*' -exec rm {} \;
