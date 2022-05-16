#include<stdio.h>


//goal to ouput max profit

int max(int a,int b){
    if(a>b) return a;
    return b;
}


int Knapsack(int weights[],int profits[],int n,int w){

    int dp[n+1][w+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                //if the number of items that we have are 0 or the weight of the knapsack is 0 then the max profit will be zero
               dp[i][j]=0;
            }

            else if(weights[i-1]>w){
                //now if the weight of the current item is exceeding the weight of knapsack then we backtrack and consider the profit excluding the item
                dp[i][j]=dp[i-1][j];
            }

            else{
                //now if the weight of the current item is less than the weigth of the knapsack then we take the max of excluding the item and including the item
                dp[i][j]=max(dp[i-1][j],profits[i-1]+dp[i-1][j - weights[i-1]]);
            }
        }
    }
    return dp[n][w];
}
int main(){

    int n=3,w=6;
    // scanf("%d %d",&n,&w);
    int weights[3]={2,3,3};
    int profits[3]={1,2,4};
    // for(int i=0;i<=n;i++){
    //     scanf("%d",&weights[i]);
    // }
    // for(int i=0;i<=n;i++){
    //     scanf("%d",&profits[i]);
    // }
    // for(int i=0;i<=n;i++){
    //     printf("%d ",weights[i]);
    // }
    // for(int i=0;i<=n;i++){
    //     printf("%d ",profits[i]);
    // }
    printf("The max capacity is %d and no of items is %d",w,n);

    printf("The max profit is %d",Knapsack(weights,profits,n,w));



    return 0;
}