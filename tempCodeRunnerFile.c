#include<stdio.h>
#define INT_MAX 1e5

int min(int a,int b){
    if(a<b) return a;
    return b;
}

int coinChangeDP(int coins[],int n_coins,int amount){
    int dp[n_coins+1][amount+1];

    for(int i=0;i<=n_coins;++i){
        //here i is the number f coins we are having to make the amount j
        for(int j=0;j<=amount;++j){

            if(j==0){
                //If the amount to be formed is 0 then no matter
                //how many coins we have the answer will be 0
                dp[i][j]=0;
            }
            else  if(i==0){
                //that is the number of coins that we have are 0
                //then we assign dp[i][j] as 10^5
                dp[i][j]=1e5;
            }
            else if(coins[i-1]>j){
                //that is we are not able to include the coin
                //we exclude it and go one level back and copy the solution
                dp[i][j]=dp[i-1][j];
            }

            else{
                //now we can include the coin to make up the amount 
                //now we have to take the min of including and not including the coin
                //dp[i][j]=min(inclusion,exclusion)
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }

            
        }
    }

    // for(int i=0;i<=n_coins;i++){
    //         for(int j=0;j<=amount;j++){
    //             printf("%d ",dp[i][j]);
    //         }
    //         printf("\n");
    // }
    return dp[n_coins][amount]>1e4 ? -1:dp[n_coins][amount];

}


int main(){

    int n_coins;
    int amount;
    printf("Enter the amount to be formed:");
    scanf("%d",&amount);
    printf("Enter the number of coins:");
    scanf("%d",&n_coins);
    int coins[n_coins];
    printf("Enter the coins\n");
    for (int i = 0; i < n_coins; i++)
    {
        printf("Enter the value of coin %d ",i+1);
        scanf("%d",&coins[i]);
    }
    int answer=coinChangeDP(coins,n_coins,amount);
    if(answer==-1){
        printf("Amount cannot be formed with the coins");
    }
    else{
        printf("Minimum number of coins %d",answer);
    }
}