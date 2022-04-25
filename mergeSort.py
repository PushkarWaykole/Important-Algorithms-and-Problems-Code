def merge_sort(arr):
    if len(arr) <= 1:
        return

    mid = len(arr)//2

    left = arr[:mid]
    right = arr[mid:]

    merge_sort(left)
    merge_sort(right)

    merge_two_sorted_lists(left, right, arr)

def merge_two_sorted_lists(a,b,arr):
    len_a = len(a)
    len_b = len(b)

    left_pointer = right_pointer = k = 0
    

    while left_pointer < len_a and right_pointer < len_b:
        if a[left_pointer] <= b[right_pointer]:
            arr[k] = a[left_pointer]
            left_pointer+=1
        else:
            arr[k] = b[right_pointer]
            right_pointer+=1
        k+=1

    while left_pointer < len_a:
        arr[k] = a[left_pointer]
        left_pointer+=1
        k+=1

    while right_pointer < len_b:
        arr[k] = b[right_pointer]
        right_pointer+=1
        k+=1      
        
print("Enter the array")
arr=list(map(int,input().split()))
print("The entered array is:")
print(arr)
merge_sort(arr)
print("The sorted array using merge sort is:")
print(arr)