from sys import argv
from random import randint
#argv[1] is array comma delimited

def qsort(arr):
    global count
    n = len(arr)
    if n > 1:
        randIdx = randint(0, n-1)
        temp = arr[randIdx]
        arr[randIdx] = arr[0]
        arr[0] = temp
        pivot = arr[0]
        i = 1
        for j in range(1, n):
            if arr[j] < pivot:
                temp = arr[j]
                arr[j] = arr[i]
                arr[i] = temp
                i =i + 1
        temp = arr[i-1]
        arr[i-1] = pivot
        arr[0] = temp
        return qsort(arr[:i-1])+[pivot]+qsort(arr[i:])
    else:
        return arr

array = [int(x) for x in argv[1].split(",")]                

arr = qsort(array)
print arr
