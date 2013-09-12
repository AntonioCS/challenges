/**
 * 
 * http://www.reddit.com/r/dailyprogrammer/comments/pih8x/easy_challenge_1/
 create a program that will ask the users name, age, and reddit username. have it tell them the information back, in the format:

your name is (blank), you are (blank) years old, and your username is (blank)

for extra credit, have the program log this information in a file to be accessed later.

 
 */
#include <stdio.h>


int logData(char *, char *, int);

int main(int argc, char *argv[]) {
    
    char name[100] = { 0 };
    char username[100] = { 0 };   
    int age = 0;
    
    printf("Name: ");    
    scanf("%s", name);
    printf("Age: ");    
    scanf("%d", &age);
    printf("Username: ");    
    scanf("%s", username);
        
    printf("your name is %s, you are %d years old, and your username is %s\n",name,age,username);
    logData(name,username,age);
    
    return 0;
}

int logData(char *name, char *username, int age) {
    FILE *fp = fopen("challenge_1_easy_log","a");
    
    if (fp) {
        fprintf(fp,"Name:%s\nAge:%d\nUsername:%s\n",name,age,username);
        fclose(fp);
        
        return 0;
    }
    
    return 1;
}
//*/