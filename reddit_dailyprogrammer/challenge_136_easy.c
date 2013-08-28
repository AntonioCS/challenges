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
#include <stdbool.h>


#define MAXSIZE 100

struct studentList {
    struct student **list;
    float list_avg;
};

struct student {
    char *name;
    int *assignments;
    float avg;
};

/*
 * 
 */
int main(int argc, char** argv) {

    //state 0 - Not started
    //state 1 - Have read the number of students and assignments - Set up students list
    //state 2 - Started reading students with their grades in the assignments
    int state = 0;

    struct studentList stList = {NULL, 0};
    char *data = calloc(MAXSIZE, 1);
    int totalStudents = 0;
    int totalAssignments = 0;

    while (1) {
        switch (state) {
            case 0://get the number of students and assignments
                ++state;

                //must have the \n
                scanf("%d %d\n", &totalStudents, &totalAssignments);
                break;
            case 1:
                ++state;

                if (totalStudents <= 0 || totalAssignments <= 0) {
                    printf("ERROR\n");
                    goto loop_exit;
                }

                stList.list = malloc(sizeof (struct student) * totalStudents);
                break;
            case 2://Read all the students names and grades
                ++state;

                //printf("Total students -> %d\n",totalStudents);
                char *ptr = NULL;
                struct student *st = NULL;

                for (int x = 0; x < totalStudents; x++) {
                    fgets(data, MAXSIZE, stdin);
                    //printf("Data read -> %s",data);
                    ptr = strtok(data, " ");

                    if (ptr == NULL) {
                        printf("Error no data given\n");
                        goto loop_exit;
                    }

                    st = calloc(sizeof (struct student), 1);

                    if (st == NULL) {
                        printf("Unable to allocate space for student\n");
                        goto loop_exit;
                    }

                    st->name = calloc(MAXSIZE, 1);
                    st->assignments = calloc(sizeof (int), totalAssignments);

                    if (st->name == NULL || st->assignments == NULL) {
                        free(st);
                    }

                    strcpy(st->name, ptr);

                    int a = 0;
                    ptr = strtok(NULL, " "); //Start getting the numbers

                    while (a < totalAssignments) {
                        if (ptr == NULL) {
                            printf("Error - Missing Assignments");
                            goto loop_exit;
                        }

                        st->assignments[a++] = atoi(ptr);

                        ptr = strtok(NULL, " ");
                    }

                    stList.list[x] = st;
                    memset(data, 0, MAXSIZE);
                }
                break;
            case 3://We have all the students with their assignments, so we can make all the calculations        
                {
                ++state;
                
                int sum = 0;
                for (int i = 0; i < totalStudents; i++) {
                    sum = 0;
                    for (int a = 0; a < totalAssignments; a++) {
                        sum += stList.list[i]->assignments[a];
                    }

                    stList.list[i]->avg = sum / ((float)totalAssignments);
                    stList.list_avg += stList.list[i]->avg;
                }

                stList.list_avg /= (float) totalStudents;
                }
                break;
            case 4: //show result
                printf("%.2f\n", stList.list_avg);
                for (int i = 0; i < totalStudents; i++) {
                    printf("%s %.2f\n", stList.list[i]->name, stList.list[i]->avg);
                }
                goto loop_exit;
                break;
        }
    }

loop_exit:

    free(data);
    return 0;
}

