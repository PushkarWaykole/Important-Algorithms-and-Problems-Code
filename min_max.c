#include<stdio.h>

struct Pair{
    int min;
    int max;
};

struct Pair getminmax(int arr[],int start,int end){
    struct Pair result;
    //If the array contains only one element
    if(end-start==0){
        result.min=result.max=arr[start];
        return result;
    }

    //Is the array contains 2 elements
    if(end-start==1){
        if(arr[start]>arr[end]){
            result.max=arr[start];
            result.min=arr[end];
        }
        else{
            result.max=arr[end];
            result.min=arr[start];
        }
        return result;
    }

    int mid=(start+end)/2;
    struct Pair left=getminmax(arr,start,mid);
    struct Pair right=getminmax(arr,mid+1,end);

    if(left.min<right.min){
        result.min=left.min;
    }
    else{
        result.min=right.min;
    }

    if(left.max>right.max){
        result.max=left.max;
    
    }
    else{
        result.max=right.max;
    }

    return result;

}

int main(){
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element :");
        scanf("%d",&arr[i]);
    }
    printf("The array is:");
    for (int  i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    struct Pair answer=getminmax(arr,0,n-1);
    printf("The maximum element is: %d and the minimum element is: %d",answer.max,answer.min);
    
    
    return 0;
}

