#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Coin Change Problem
   Link: https://www.hackerrank.com/challenges/coin-change/submissions/code/13309791
*/

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int amount;
    int numberofCoins;
    scanf("%d %d",&amount,&numberofCoins);
    int change[numberofCoins];
    int i;
    //int numberofWays = 0;
    for(i=0;i<numberofCoins;i++){
        scanf("%d",&change[i]);
    }
    if(amount>250 && numberofCoins>50) return 0;
    long long int nWays[amount+1];
    //initializing base cases
    nWays[0] = 1;
    for(i=1;i<=amount;i++)
        nWays[i] = 0;
    for(i=0;i<numberofCoins;i++){
        //int sum = 0;
        int j;
        for(j=change[i];j<=amount;j++){
           int index = j-change[i];
           //if(index < 0) continue;
           nWays[j] = nWays[j] + nWays[index];// sum =1 2 2
        }
        //nWays[i] = sum;// 0-1 1-1 2-2
        //numberofWays = numberofWays + nWays[i];//1 3
    }
    printf("%lld",nWays[amount]);
    
    return 0;
}

