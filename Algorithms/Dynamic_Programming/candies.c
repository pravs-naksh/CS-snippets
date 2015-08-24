#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Candies Problem
   Link: https://www.hackerrank.com/challenges/candies/submissions/code/13311268
*/

int main() {

    int i, n, rank[100010], candy[100010], candy_rev[100010];
    long int sum;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &rank[i]);
        candy[i] = candy_rev[i] = 1;
    }
    
    for (i = 1; i < n; i++) {
        if (rank[i] > rank[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }
    
    for (i = n - 2; i >= 0; i--) {
        if (rank[i] > rank[i + 1]) {
            candy_rev[i] = candy_rev[i + 1] + 1;
        }
    }
    
    sum = 0;
    for (i = 0; i < n; i++) {
        if (candy_rev[i] > candy[i]) {
            sum += candy_rev[i];
        } else {
            sum += candy[i];
        }
    }
    printf("%ld\n", sum);
    
    return 0;
}


