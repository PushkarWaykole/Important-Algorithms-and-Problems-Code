#include <stdio.h>
#define INT_MAX 9999999
int dp[100][100];

int min(int x, int y){
    if(x<y) return x;
    return y;
}

int matrixChain(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		dp[i][j] = min(
			dp[i][j], matrixChain(p, i, k)
					+ matrixChain(p, k + 1, j)
					+ p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}


int main()
{
    int n;
    printf("Entre the number of elements in the matrix array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the sizes of the matrices:");
    for(int i = 0; i < n; i++){
        printf("Enter size %d",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            dp[i][j]=-1;
        }
    }


	printf("Minimum number of multiplications is %d",matrixChain(arr,1, n-1));
}


