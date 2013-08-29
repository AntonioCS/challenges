CFLAGS=-Wall -g -std=c99 -o
CC=gcc

challenge_136_easy: challenge_136_easy.c
	$(CC) $(CFLAGS) $@ challenge_136_easy.c
	
challenge_136_easy_test: challenge_136_easy
	echo "Using Data"
	cat challenge_136_easy_test_data
	./challenge_136_easy < challenge_136_easy_test_data
	
clean:
	rm -rf $(FILE)
