/*
 * http://en.wikipedia.org/wiki/Caesar_cipher
 * http://www.reddit.com/r/dailyprogrammer/comments/pkw2m/2112012_challenge_3_easy/
 * 
 Welcome to cipher day!

write a program that can encrypt texts with an alphabetical caesar cipher. This cipher can ignore numbers, symbols, and whitespace.

for extra credit, add a "decrypt" function to your program!

 
 */

#include <stdio.h>


#define SHIFT 5


void caesar_cipher_encrypt(char *,int);
void caesar_cipher_decrypt(char *,int);

int main(int argc,char **argv) {
    
    char msg[256] = { 0 };
    
    printf("Insert msg: ");
    fgets(msg,255,stdin);
    //scanf("%s",msg);
    
    if (msg != NULL) {
        caesar_cipher_encrypt(msg,SHIFT);

        printf("encrypted: %s\n",msg);

        caesar_cipher_decrypt(msg,SHIFT);
        printf("decrypted: %s\n",msg);
    }
    return 0;
}

void caesar_cipher_encrypt(char *text,int shift) {    
    while(*text != '\0' && *text != '\n') {        
        *text += shift;
        text++;        
    } 
}

void caesar_cipher_decrypt(char *text,int shift) {
    while(*text != '\0' && *text != '\n') {
        *text -= shift;
        text++;        
    } 
}