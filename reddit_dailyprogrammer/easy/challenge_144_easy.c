
/*
 http://www.reddit.com/r/dailyprogrammer/comments/1sob1e/121113_challenge_144_easy_nuts_bolts/
 (Easy): Nuts & Bolts

You have just been hired at a local home improvement store to help compute the proper costs of inventory.
The current prices are out of date and wrong; you have to figure out which items need to be re-labeled with the correct price.

You will be first given a list of item-names and their current price. You will then be given another list of the same item-names but with the correct price.
You must then print a list of items that have changed, and by how much.
Formal Inputs & Outputs
Input Description

The first line of input will be an integer N, which is for the number of rows in each list.
Each list has N-lines of two space-delimited strings: the first string will be the unique item name (without spaces), the second string will be the price (in whole-integer cents). The second list, following the same format, will have the same unique item-names, but with the correct price. Note that the lists may not be in the same order!
Output Description

For each item that has had its price changed, print a row with the item name and the price difference (in cents).
Print the sign of the change (e.g. '+' for a growth in price, or '-' for a loss in price). Order does not matter for output.
Sample Inputs & Outputs
Sample Input 1

4
CarriageBolt 45
Eyebolt 50
Washer 120
Rivet 10
CarriageBolt 45
Eyebolt 45
Washer 140
Rivet 10

Sample Output 1

Eyebolt -5
Washer +20

Sample Input 2

3
2DNail 3
4DNail 5
8DNail 10
8DNail 11
4DNail 5
2DNail 2

Sample Output 2

2DNail -1
8DNail +1

 */

#include <stdio.h>
#include <string.h> //memset, strcmp

#define BUFFERSIZE 100

int main(int argc, char **argv) {
    int list = 0;
    scanf("%d", &list);

    if (list > 0) {
        getchar(); //get rid of the DAMN \n

        char oldListItems[list][BUFFERSIZE];
        char newListItems[list][BUFFERSIZE];

        int oldListPrices[list];
        int newListPrices[list];

        memset(oldListPrices, 0, list);
        memset(newListPrices, 0, list);

        int t = 0;
        int max = list * 2;
        char buf[BUFFERSIZE];
        int k = 0;

        while (t < max) {
            memset(buf, 0, BUFFERSIZE);

            fgets(buf, BUFFERSIZE, stdin);

            if (t >= list) {
                memset(newListItems[k], 0, BUFFERSIZE);
                sscanf(buf, "%s %d", newListItems[k], &newListPrices[k]);
                k++;
            } else {
                memset(oldListItems[t], 0, BUFFERSIZE);
                sscanf(buf, "%s %d", oldListItems[t], &oldListPrices[t]);
            }

            t++;
        }

        for (int i = 0; i <= list; i++) {
            for (int x = 0; x <= list; x++) {
                if (strcmp(oldListItems[i], newListItems[x]) == 0) {
                    if (oldListPrices[i] != newListPrices[x]) {
                        printf("%s ", oldListItems[i]);
                        if (oldListPrices[i] > newListPrices[x]) {
                            printf("-%d\n", oldListPrices[i] - newListPrices[x]);
                        } else {
                            printf("+%d\n", newListPrices[x] - oldListPrices[i]);
                        }
                    }

                    break;
                }
            }
        }
    }
}