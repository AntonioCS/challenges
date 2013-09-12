


/*
http://www.reddit.com/r/dailyprogrammer/comments/pm6oj/2122012_challenge_4_easy/
You're challenge for today is to create a random password generator!

For extra credit, allow the user to specify the amount of passwords to generate.

For even more extra credit, allow the user to specify the length of the strings he wants to generate!
 * 
 */ 


#include <stdio.h>
#include <stdlib.h>

char *randstring(int);

int main() {
    
    int nPasswords = 0;
    int pSize = 0;
    
    printf("How many passwords: ");
    scanf("%d",&nPasswords);
    printf("Password length: ");
    scanf("%d",&pSize);
    
    
    while (nPasswords--) {
        printf("%s\n",randstring(pSize));
    }
    
    return 0;
}

char *randstring(int length) {
    
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;
    
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            int key = 0;
            int l = (int)(sizeof(charset) -1);
            
            for (int n = 0;n < length;n++) {            
                key = rand() % l;
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }
    
    return randomString;
}