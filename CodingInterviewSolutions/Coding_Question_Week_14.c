
/**
  Coding Question Week #14

Question:

Given a string that contains words separated by spaces, write a function that reverses the order of the words.

Note: The input string is represented as an array of characters.

Example:

Example input string:
"Coding Interview Solutions Manual"
Example output string:
"Manual Solutions Interview Coding"
 
 
 */
#define MAX_TEXT 100

#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //realloc


int main(int argc, char **argv) {
    char text[MAX_TEXT] = { 0 };    
    char *parts = NULL;
    
    printf("Insert string: ");
    fgets(text,MAX_TEXT,stdin);
    sscanf(text,"%[^\n]",text); //remove the \n
    
    
    char **reverse = NULL;
    char **extra = NULL;
    int size = 0;
    int i = 0;
    
    parts = strtok (text," ");
    while (parts != NULL) {
        
        size += ((strlen(parts)) * sizeof(char));
        extra = realloc(reverse,size);

        if (extra) {
            reverse = extra; 
            reverse[i++] = parts;
        }     
        else {
            printf("Error allocating memory\n");
            exit(1);
        }
                
        parts = strtok (NULL, " ");
    }
    
    while (--i >= 0) {
        printf("%s ",reverse[i]);                
    }
    
    printf("\n");
}
