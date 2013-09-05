CFLAGS=-Wall -g -std=c99 -o
CC=gcc

insertionsort1: insertionsort1.c
	$(CC) $(CFLAGS) $@ insertionsort1.c
	
insertionsort1_test: insertionsort1
	./insertionsort1 < insertionsort1_test_data		
	
insertionsort1_test2: insertionsort1
	./insertionsort1 < insertionsort1_test_data_2	
clean:
	rm -rf $(FILE)
