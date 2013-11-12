/*
http://www.reddit.com/r/dailyprogrammer/comments/1q6pq5/11413_challenge_140_easy_variable_notation/
 * 
 When writing code, it can be helpful to have a standard (Identifier naming convention) that describes how to define all your variables and object names. This is to keep code easy to read and maintain. Sometimes the standard can help describe the type (such as in Hungarian notation) or make the variables visually easy to read (CamcelCase notation or snake_case).

Your goal is to implement a program that takes an english-language series of words and converts them to a specific variable notation format. Your code must support CamcelCase, snake_case, and capitalized snake_case.
Formal Inputs & Outputs
Input Description

On standard console input, you will be given an integer one the first line of input, which describes the notation you want to convert to. If this integer is zero ('0'), then use CamcelCase. If it is one ('1'), use snake_case. If it is two ('2'), use capitalized snake_case. The line after this will be a space-delimited series of words, which will only be lower-case alpha-numeric characters (letters and digits).
Output Description

Simply print the given string in the appropriate notation.
Sample Inputs & Outputs
Sample Input

0
hello world

1
user id

2
map controller delegate manager

Sample Output

0
helloWorld

1
user_id

2
MAP_CONTROLLER_DELEGATE_MANAGER

Difficulty++

For an extra challenge, try to convert from one notation to another. Expect the first line to be two integers, the first one being the notation already used, and the second integer being the one you are to convert to. An example of this is:

Input:

1 0
user_id

Output:

userId

 */
#include <stdio.h>
#include <stdbool.h> //bool
#include <string.h>
#include <ctype.h> //toupper

void camel_case(char *);
void snake_case(char *);
void c_snake_case(char *);


#define STRING_LIMIT 250

int main(int argc,char **argv) {
    int type = 0;
    char string[STRING_LIMIT] = {0};
    
    scanf("%d",&type);
    getchar();//remove the damn \n
    
    fgets(string,STRING_LIMIT,stdin);
    
    switch(type) {
        case 0://CamelCase
            camel_case(string);
        break;
        case 1://snake_case
            snake_case(string);
        break;
        case 2://capitalize snake_case 
            c_snake_case(string);
        break;  
    }
    
    printf("%d\n%s\n",type,string);
}

void camel_case(char *s) {
    
    char *p = NULL;
    char newString[STRING_LIMIT];    
    int n = 0;
    
    memset(newString,0,STRING_LIMIT);
    p = strtok (s," ");
    
    while (p != NULL) {        
        
        if (n++ != 0) {
            *p = toupper(*p);
        }
        
        strcat(newString,p);        
        p = strtok (NULL," ");        
    }
    
    memset(s,0,STRING_LIMIT);
    strcpy(s,newString);
    s[strlen(s)-1] = '\0';
}

void snake_case(char *s) {
    while (*s != '\n') {
        if (*s == ' ') {
            *s = '_';
        }
        
        s++;
    }
    *s = '\0';
}

void c_snake_case(char *s) {
    snake_case(s);
    
    while (*s != '\0') {
        if (*s != '_') {
            *s = toupper(*s);
        }
        
        s++;
    }
}