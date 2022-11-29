CC=gcc
CFLAGS=-Wall

Ex2: 
	$(CC) Ex2.c $(CFLAGS) -o Ex2

clean:
	rm -rf Ex2
	rm -rf *.epub
	rm -rf *.zip