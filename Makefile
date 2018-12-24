CFLAGS = -Wall -std=c99 -pthread 

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

all:  threads


threads:  threads.o
	gcc -pthread  -o $@ $<


