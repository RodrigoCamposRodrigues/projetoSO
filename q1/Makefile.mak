CC=gcc
CFLAGS=-Wall 

Ex1: 
	$(CC) Ex1.c $(CFLAGS) -o Ex1

clean:
	rm -rf Ex1