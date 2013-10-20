
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
#define MAX_TEXT 500

#include <stdio.h>
#include <string.h> //strchr
#include <stdlib.h> //realloc


int main(int argc, char **argv) {
    char text[MAX_TEXT] = { 0 };        
    
    printf("Insert string: ");
    fgets(text,MAX_TEXT,stdin);
    //sscanf(text,"%[^\n]",text); //remove the \n <-- Undefined behaviour :D "if copying takes place between objects that overlap, the behavior is undefined."
    char *theEnter = strchr(text,'\n');
    if (theEnter) {
        *theEnter = 0;//remove \n
    }        
    
    char **reverse = NULL;
    char **extra = NULL;
    char *parts = NULL;
    int size = 0;
    int i = 0;
    size_t increse_by = sizeof(char *);
    
    parts = strtok (text," ");
    while (parts != NULL) {
                
        size += increse_by; //pointer to pointer so increase by the size of new pointer
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