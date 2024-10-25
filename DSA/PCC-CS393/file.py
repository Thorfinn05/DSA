import random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

i=0
integers=[]
while (i<=100):
    data=random.randint(0,1000)
    integers.append(data)
    i=i+1

with open("file.txt","w")as file:
    for i in integers:
        file.write(str(i)+' ')
file.close()

file=open("file.txt","r")
data=file.read()
print(data)
file.close()

integernew= bubble_sort(integers)


with open("sort.txt","w")as file:
    for i in integernew:
        file.write(str(i)+' ')
file.close()