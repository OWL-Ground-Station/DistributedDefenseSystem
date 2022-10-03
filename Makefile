CC=gcc

CFLAGS = -c

all: peer

peer: p2p.o diagnose.o
	$(CC) -o peer p2p.o diagnose.o

clean:
	rm *.o
	rm peer

%.o: %.c
	$(CC) $(CFLAGS) $*.c