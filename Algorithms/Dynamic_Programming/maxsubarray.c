#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int cases,inputSize;
    // cases : 2
    scanf("%d",&cases);
    //printf("%d\n",cases);
    int i;
    
    //constraints
    if(cases > 10) cases = 10;
    if(cases < 1) return 0;
    
    for(i=0;i<cases;i++){
       //is : 4 6 
       scanf("%d",&inputSize);
       
       //lenght cannot be less than 1 
       if(inputSize < 1) continue;
       
       int arr[inputSize];
       int j;
        //loop for 4 and 6
       for(j=0;j<inputSize;j++){
           scanf("%d",&arr[j]);
       }
       //now computing for each array
       //now computing for contiguous
       int max_cg = 0;
       int sum = 0;
       
       for(j=0;j<inputSize;j++){
           sum = sum + arr[j]; // 0 - 1  = -1 6 12
           if(sum < arr[j]) // -1 < -1 
               sum = arr[j];
           
           if(j==0) max_cg = sum;
           
           if(sum > max_cg) // -1 > 0 
               max_cg = sum;// 6 
       }
       printf("%d ",max_cg);
        
       //now computing for non contiguous
       int max_ncg = 0;
       sum = 0;
       int tmp;
       for(j=0;j<inputSize;j++){
           if(j >0)
            tmp = sum;
           sum = sum + arr[j]; // 0 - 1 = -1
           if(tmp>sum && j>0) sum = tmp;
           if(sum < arr[j]) // -1 < -1 
               sum = arr[j];
           
           if(j==0) max_ncg = sum; // max
           
           if(sum > max_ncg) //
               max_ncg = sum;//  
       }
       printf("%d\n",max_ncg);
    }
    return 0;
}

