
/*
http://www.reddit.com/r/dailyprogrammer/comments/pnhyn/2122012_challenge_5_easy/

Your challenge for today is to create a program which is password protected, and wont open unless the correct user and password is given.

For extra credit, have the user and password in a seperate .txt file.

for even more extra credit, break into your own program :)
 * 
*/


#include <stdio.h>
#include <stdlib.h>

#define PFILE "challenge_5_easy_pfile"
#define MSIZE 100

FILE *pFile;

struct userData {
    char *name;
    char *password;
};


int pfileOpen();
int setUserNamePassword(struct userData*);
void pClose();


int main() {
    struct userData user = {        
        .name = calloc(MSIZE,1), 
        .password = calloc(MSIZE,1) 
    };        
    
    if (!pfileOpen()) {        
        printf("Please insert username (no spaces): ");
        scanf("%s",user.name);
        
        //disable console output
        //http://www.cplusplus.com/forum/beginner/43683/
        //http://stackoverflow.com/questions/6899025/hide-user-input-on-password-prompt
        printf("Please insert password (no spaces): ");
        scanf("%s",user.password);    
        
        setUserNamePassword(&user);        
    }
    
    pClose();
    
    return 0;
}


int pfileOpen() {    
    pFile = fopen(PFILE,"rb");
    return (pFile) ? 1 : 0;        
}

int setUserNamePassword(struct userData *u) {
    pFile = fopen(PFILE,"wb");
    if (pFile) {
        fwrite(u->name,MSIZE,1,PFILE);
    }
    else {
        return 0;
    }    
}

void pClose() {
    if (pFile) {
        fclose(pFile);
    }
}
