#Write a python program to delete nth character or a substring from a string.
str="Achivement"
n=int(input("Enter position: "))
d=int(input("Enter substring length to delete: "))
str1= str[:n] + str[n+d:]
print(str1)