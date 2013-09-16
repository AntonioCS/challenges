
/*
http://www.reddit.com/r/dailyprogrammer/comments/pnhyn/2122012_challenge_5_easy/

Your challenge for today is to create a program which is password protected, and wont open unless the correct user and password is given.

For extra credit, have the user and password in a seperate .txt file.

for even more extra credit, break into your own program :)
 * 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PFILE "challenge_5_easy_pfile"
#define MSIZE 100

FILE *pFile;

struct userData {
    char *name;
    char *password;
};


int pfileOpen();
int setUserNamePassword(struct userData*);
int getUserNamePassword(struct userData*);

void pOpen();
void pClose();
void readInput(int, char *, char *);

int main() {
    struct userData user = {        
        .name = calloc(MSIZE,1), 
        .password = calloc(MSIZE,1) 
    };                
    
    if (!pfileOpen()) {        
        printf("Please insert username: ");
        readInput(MSIZE,"%[^\n]s",(&user)->name);        
                
        //disable console output
        //http://www.cplusplus.com/forum/beginner/43683/
        //http://stackoverflow.com/questions/6899025/hide-user-input-on-password-prompt
        
        printf("Please insert password: ");        
        readInput(MSIZE,"%[^\n]s",(&user)->password);
        
        setUserNamePassword(&user);       
    }
    else {
        getUserNamePassword(&user);
        char username[MSIZE] = { 0 };
        char password[MSIZE] = { 0 };
        
        
        printf("Please insert username: ");
        readInput(MSIZE,"%[^\n]s",username);
        
        printf("Please insert password: ");
        readInput(MSIZE,"%[^\n]s",password);
        
        if (strcmp(user.name,username) == 0 && strcmp(user.password, password) == 0) {
            printf("!!! Access to the system given !!!\n");
        }
        else {
            printf("Wrong username/password\n");
        }
    }
    
    pClose();
    
    return 0;
}


int pfileOpen() {    
    pFile = fopen(PFILE,"rb");
    return (pFile) ? 1 : 0;        
}

/**
 * 
 * @param format Specification for sscanf
 * @param destination Where to write (for now it just handles one pointer)
 */
void readInput(int size, char *format, char *destination) {
    char buffer[size];
    memset(buffer,0,size);
    
    fgets(buffer,size,stdin);
    sscanf(buffer,format,destination);
}

int setUserNamePassword(struct userData *u) {    
    pOpen();
    
    if (pFile) {
        fwrite(u->name,MSIZE,1,pFile);
        fwrite(u->password,MSIZE,1,pFile);
        
        return 0;
    }
    
    return 1;         
}

int getUserNamePassword(struct userData *u) {
    pOpen();
    
    if (pFile) {   
        
        fread(u->name,MSIZE,1,pFile);
        fread(u->password,MSIZE,1,pFile);
        
        return 0;
    }
    
    return 1;
}


void pOpen() {
    if (pFile == NULL) {
        pFile = fopen(PFILE,"wb");    
    }
}

void pClose() {
    if (pFile) {
        fclose(pFile);
    }
}
