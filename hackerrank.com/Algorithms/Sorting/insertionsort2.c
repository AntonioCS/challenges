/* 
 * File:   insertsort2.c
 * Author: antoniocs
 *
 * Created on 06 September 2013, 13:50
 */

#include <stdio.h>
#include <stdlib.h>

void printArray(int a[],int size) {
    for (int i = 0;i<size;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

/* Head ends here */
void insertionSort(int ar_size, int * ar) {    
    int x = 0;
    int tmp = 0;
    int print = 0;
    
    for(int i = 1;i<ar_size;i++) {
        x = i;
        print = 0;
        
        while(x) {
            if (ar[x] < ar[x-1]) {
                tmp = ar[x-1];
                ar[x-1] = ar[x];                
                ar[x] = tmp;
                            
            }
            else {
                print = 1;
                break;
            }
            
            x--;
        }
        
        if (print) {
            printArray(ar,ar_size);
        }
    }
}

/* Tail starts here */
int main(void) {

    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }

    
    insertionSort(_ar_size, _ar);

    return 0;
}