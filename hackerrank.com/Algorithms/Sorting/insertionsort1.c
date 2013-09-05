
/*
 https://www.hackerrank.com/challenges/insertionsort1
 * 
 * 
 * 
Sample Input

5
2 4 6 8 3

Sample Output

2 4 6 8 8 
2 4 6 6 8 
2 4 4 6 8 
2 3 4 6 8 

 * 
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

void printArray(int a[],int size) {
    for (int i = 0;i<size;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {

    int sizeOfArray = 0;    
    scanf("%d",&sizeOfArray);
    
    int array[sizeOfArray];
    int tmp = 0;
    
    for (int i = 0; i < sizeOfArray;i++) {
        scanf("%d",&array[i]);
    }

    tmp = array[sizeOfArray-1];        
    int tm = 0;
    
    for (int i = sizeOfArray-2;i >= 0;i--) {        
        if (array[i] > tmp) {
            array[i+1] = array[i];
        }
        else {            
			if (i == (sizeOfArray-2)) {
				tm = 1;
        		printArray(array,sizeOfArray);                
				break;
			}
            array[i+1] = tmp;                        
            tm = 1;
			break;
        }
        
        printArray(array,sizeOfArray);                
    }        
    
    if (tm == 0) {
        array[0] = tmp;
    }

    printArray(array,sizeOfArray);
}
