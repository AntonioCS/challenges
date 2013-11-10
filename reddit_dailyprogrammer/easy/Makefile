CFLAGS=-Wall -g -std=c99 -o
CC=gcc

challenge_136_easy: challenge_136_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_136_easy_test: challenge_136_easy
	echo "Using Data"
	cat challenge_136_easy_test_data
	./challenge_136_easy < challenge_136_easy_test_data	

challenge_1_easy: challenge_1_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_3_easy: challenge_3_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_4_easy: challenge_4_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_5_easy: challenge_5_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_137_easy: challenge_137_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_137_easy_test: challenge_137_easy
	echo "Using Data"
	cat challenge_137_easy_test_data
	./challenge_137_easy < challenge_137_easy_test_data	
	
#Needs -lm flag to link to math lib
#http://stackoverflow.com/questions/5005363/undefined-reference-to-sin-in-c
#must be specified at the end
challenge_6_easy: challenge_6_easy.c
	$(CC) $(CFLAGS) $@ $< -lm
	
challenge_7_easy: challenge_7_easy.c
	$(CC) $(CFLAGS) $@ $<
	
challenge_138_easy: challenge_138_easy.c
	$(CC) $(CFLAGS) $@ $< -lm
	
challenge_139_easy: challenge_139_easy.c
	$(CC) $(CFLAGS) $@ $<