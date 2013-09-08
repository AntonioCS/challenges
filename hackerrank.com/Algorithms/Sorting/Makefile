CFLAGS=-Wall -g -std=c99 -o
CC=gcc

insertionsort1: insertionsort1.c
	$(CC) $(CFLAGS) $@ insertionsort1.c
	
insertionsort1_test: insertionsort1
	./insertionsort1 < test_data/insertionsort1_test_data_1	
	
insertionsort1_test2: insertionsort1
	./insertionsort1 < test_data/insertionsort1_test_data_2
	
insertionsort1_test3: insertionsort1
	./insertionsort1 < test_data/insertionsort1_test_data_3

insertionsort1_test4: insertionsort1
	./insertionsort1 < test_data/insertionsort1_test_data_4


insertionsort2: insertionsort2.c
	$(CC) $(CFLAGS) $@ insertionsort2.c

insertionsort2_test: insertionsort2
	./insertionsort2 < test_data/insertionsort2_test_data_1
	
insertionsort2_test2: insertionsort2
	cat test_data/insertionsort2_test_data_2
	./insertionsort2 < test_data/insertionsort2_test_data_2


insertionsort_advancedanalysis: insertionsort_advancedanalysis.c
	$(CC) $(CFLAGS) $@ insertionsort_advancedanalysis.c
	
insertionsort_advancedanalysis_test1: insertionsort_advancedanalysis	
	./insertionsort_advancedanalysis < test_data/insertionsort_adavancedanalysis_test_data_1
	
insertionsort_advancedanalysis_test2: insertionsort_advancedanalysis	
	./insertionsort_advancedanalysis < test_data/insertionsort_adavancedanalysis_test_data_2