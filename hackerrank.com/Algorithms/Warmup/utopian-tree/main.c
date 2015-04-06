#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define CYCLE_SPRING 1
#define CYCLE_SUMMER 2

int cycleSpring(int h) {
    return h * 2;
}

int cycleSummer(int h) {
    return h + 1;
}

//https://www.hackerrank.com/challenges/utopian-tree
int main() {
    int t;
    int cycles;    

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &cycles);
        int season = CYCLE_SPRING;
        int tree = 1;

        while (cycles-- > 0) {
            switch (season) {
                case CYCLE_SPRING:
                    tree = cycleSpring(tree);
                    season = CYCLE_SUMMER;
                    break;
                case CYCLE_SUMMER:
                    tree = cycleSummer(tree);
                    season = CYCLE_SPRING;
                    break;
            }
        }

        printf("%d\n", tree);
    }

    return 0;
}
