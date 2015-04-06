#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int biggest_xor = 0;

    for (int i = l; i <= r; i++) {
        for (int x = l;x <= r; x++) {
            int current_xor = i ^ x;

            if (current_xor > biggest_xor) {
                biggest_xor = current_xor;
            }
        }
    }

    return biggest_xor;
}

int main() {
    int res;
    int _l;
    scanf("%d", &_l);

    int _r;
    scanf("%d", &_r);

    res = maxXor(_l, _r);
    printf("%d", res);

    return 0;
}
