
/*
 * 
 http://www.reddit.com/r/dailyprogrammer/comments/pr2xr/2152012_challenge_7_easy/
 * 
 Write a program that can translate Morse code in the format of ...---...

A space and a slash will be placed between words. ..- / --.-

For bonus, add the capability of going from a string to Morse code.

Super-bonus if your program can flash or beep the Morse.

This is your Morse to translate:

.... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--

 */
#include <stdio.h>
#include <string.h>

#define BSIZE 15

char *morseToLetter(char *);


int main() {
    char *morseCode = ".... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--";    
    char buffer[BSIZE] = { 0 };
    int bufferKey = 0;

    for(int i=0,t = strlen(morseCode)+1;i<t;i++) {
        if (morseCode[i] == '/') {
            printf(" ");
        }
        else {
            if (morseCode[i] == ' ') {
                if (strlen(buffer) == 0) {
                    continue;
                }
                
                printf("%s",morseToLetter(buffer));
                
                memset(buffer,0,BSIZE);
                bufferKey = 0;
            }
            else {
                buffer[bufferKey++] = morseCode[i];
            }            
        }        
    }
    
    if (strlen(buffer) > 0) {      
        printf("%s",morseToLetter(buffer));                
    }
                
    printf("\n");
 
    return 0;
}

char *morseToLetter(char *morseLetter) {
    static char morse[][BSIZE] = {
		".-","A",
        "-...","B",
        "-.-.","C",
        "-..","D",
        ".","E",
        "..-.","F",
        "--.","G",
        "....","H",        
        "..","I",
        ".---","J",
        "-.-","K",
        ".-..","L",
        "--","M",
        "-.","N",
        "---","O",
        ".--.","P",
        "--.-","Q",
        ".-.","R",
        "...","S",
        "-","T",
        "..-","U",
        "...-","V",
        ".--","W",
        "-..-","X",
        "-.--","Y",
        "--..","Z"
    };
    static int morseTotal = sizeof(morse)/sizeof(morse[0]);
    
    for (int i = 0;i<morseTotal;i +=2) {        
        if (strcmp(morseLetter,morse[i]) == 0) {
            return morse[i+1];
        }
    }
    
    return '\0';
}



