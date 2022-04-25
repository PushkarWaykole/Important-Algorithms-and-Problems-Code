 
# def quicksort(arr,left,right):
#     if(left<right):
#         partition_pos=partition(arr,left,right)
#         quicksort(arr,left,partition_pos-1)
#         quicksort(arr,partition_pos+1,right)    

# def partition(arr,left,right):
#     i=left
#     j=right-1
#     pivot=arr[right]
    
#     while(i<j):
#         while i<right and arr[i]<pivot:
#             i+=1
#         while j>left and arr[j]>=pivot:
#             j-=1
#         if(i<j):
#             arr[i],arr[j]=arr[j],arr[i]
    
#     #Swap the element at right th position with the pivot element that is at right th position
#     arr[i],arr[right]=arr[right],arr[i]
#     return i




# print("Enter the array")
# arr=list(map(int,input().split()))
# print("The entered array is:")
# print(arr)
# quicksort(arr,0,len(arr)-1)
# print("The sorted array using quick sort is:")
# print(arr)

def quicksort(arr,left,right):
    if(left<right):
        partition_pos=partition(arr,left,right)
        quicksort(arr,left,partition_pos-1)
        quicksort(arr,partition_pos+1,right)
        
def partition(arr,left,right):
    i=left
    j=right-1
    pivot=arr[right]
    while(i<j):
        while i<right and arr[i]<pivot:
            i+=1
        while j>left and arr[j]>=pivot:
            j-=1
        if(i<j):
            arr[i],arr[j]=arr[j],arr[i]
    if(arr[i]>pivot):                
        arr[i],arr[right]=arr[right],arr[i]
    return i
print("Enter the array")
arr=list(map(int,input().split()))
print("The entered array is:")
print(arr)
quicksort(arr,0,len(arr)-1)
print("The sorted array using quick sort is:")
print(arr)
    