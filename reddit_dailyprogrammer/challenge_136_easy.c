/* 
 * File:   main.c
 * Author: AntonioCS
 *
 * Created on 26 de Agosto de 2013, 20:18
 */
/*
 * http://www.reddit.com/r/dailyprogrammer/comments/1kphtf/081313_challenge_136_easy_student_management/
(Easy): Student Management

You are a computer science professor at South Harmon Institute of Technology, 
and are in dire need of automatic grading! The good news is you have all of your student's assignments in an easy-to-read format, 
making automation easy!

You will be given a list of unique student names, 
and then a list of their assignment grades. 
All assignments are based on 20 points and are scored in whole-numbers (integers). 
All students have received the same number of assignments, so you don't have to worry about managing jagged arrays.

Author: nint22
Formal Inputs & Outputs
Input Description

On standard console input, you will be given two space-delimited integers N and M: 
N is the number of students (which ranges from 1 to 60, inclusive), 
and M is the number of assignments (which ranges from 4 to 100, inclusive). 
This will be followed by N lines of text, 
each starting with an upper-case unique string being is your students name. 
This is then followed by M integers, which are the grades ranging from 0 to 20, inclusively.
Output Description

On the first line of output, print the class' average grade. Then, for each student, print their name and average grade (up to two decimal points precision).
Sample Inputs & Outputs
Sample Input 1

3 5
JON 19 14 15 15 16
JEREMY 15 11 10 15 16
JESSE 19 17 20 19 18

Sample Output 1

15.93
JON 15.80
JEREMY 13.40
JESSE 18.60

Sample Input 2

10 10
ABIGAIL 11 3 5 20 4 2 8 17 4 5
ALEXANDER 2 12 20 0 6 10 3 4 9 7
AVA 11 15 2 19 14 5 16 18 15 19
ETHAN 6 12 0 0 5 11 0 11 12 15
ISABELLA 16 0 10 7 20 20 7 2 0 1
JACOB 2 14 17 7 1 11 16 14 14 7
JAYDEN 10 10 3 16 15 16 8 17 15 3
MADISON 10 11 19 4 12 15 7 4 18 13
SOPHIA 5 17 14 7 1 17 18 8 1 2
WILLIAM 12 12 19 9 4 3 0 4 13 14

Sample Output 2

9.50
ABIGAIL 7.90
ALEXANDER 7.30
AVA 13.40
ETHAN 7.20
ISABELLA 8.30
JACOB 10.30
JAYDEN 11.30
MADISON 11.30
SOPHIA 9.00
WILLIAM 9.00
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentList {
    struct students *list;
    int list_avg;
};

struct student {
    char *name;
    int *assignments;
    int avg;    
};

/*
 * 
 */
int main(int argc, char** argv) {
    int state = 0;
    //state 0 - Not started
    //state 1 - Have read the number of students and assignments
    //state 3 - Started reading students with their grades in the assignments
    char *data = calloc(100,1);
    while (1) {
        switch (state) {
            case 0://get the number of students and assignments
                ++state;
                fgets(text,100,stdin);
            break;
            
        }
        
    fgets(text,10,stdin);
    /*
    if (strstr(text,"\n")) {
        printf("ta la");
    }
    else {
        printf("n ta ");
    }
    */
    //printf("acabou - %s\n",text);
        
        
    }    
}

