#include<stdio.h>


int length(char s[]){
    int count=0;
    int i=0;
    while(s[i]!='\0'){
        count++;
        i++;
    }
    return count;
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}
void commonSubstring(char* s1,char* s2){
    int k=0;
   

    int len1=length(s1);
    int len2=length(s2);
    
    int dp[len1+1][len2+1];

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            dp[i][j]=0;
        }
    }
    
    
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }

            else if(s1[i-1]==s2[j-1]){
               
                dp[i][j]=1+dp[i-1][j-1];
                

            }
            else if(s1[i-1]!=s2[j-1]){
                
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    printf("\nThe length of LCS is %d \n",dp[len1][len2]);
   
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
    int i=len1+1;
    int j=len2+1;
    char answer[dp[len1][len2]];
    int index = dp[len1][len2];
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            answer[index]=s1[i-1];
            index=index-1;
            i--;j--;
        }

        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    

    
    printf("The lcs is:%s",answer);
    


}

int main(){
    char s1[20];
    char s2[20];
    printf("Enter the first string:");
    scanf("%s",&s1);
    printf("Enter the second string:");
    scanf("%s",&s2);
    printf("%s %s",s1,s2);
    // char common[20]=commonSubstring(s1,s2);
    // printf("The longest common subsequence is %s",common);
    commonSubstring(s1,s2);
    return 0;
}