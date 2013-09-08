//https://www.hackerrank.com/challenges/insertion-sort
#include <stdio.h>
#include <stdlib.h>


int insertionSort(int ar_size, int * ar) {    
    int x = 0;    
    int tmp = 0;    
    int shifts = 0;
    
    for(int i = 1;i<ar_size;i++) {
        x = i;                
        
        while(ar[x] < ar[x-1]) {
            shifts++;
            tmp = ar[x-1];
            ar[x-1] = ar[x];
            ar[x] = tmp;
            x--;
        }            
    }
    
    return shifts;            
}

int main(void) {

    int tests = 0;
    scanf("%d", &tests);
    int results[tests];
    
    for (int i = 0;i<tests;i++) {
    
        int _ar_size;
        scanf("%d", &_ar_size);
        int _ar[_ar_size], _ar_i;
        for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
            scanf("%d", &_ar[_ar_i]);
        }


        results[i] = insertionSort(_ar_size, _ar);
    }
    
    for (int i = 0;i<tests;i++) {
        printf("%d\n",results[i]);
    }
    
    return 0;
}
