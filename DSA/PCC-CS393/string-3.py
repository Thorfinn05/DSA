#Write a python program to insert a character or a substring in a position of a string
str="Achivement"
a=input("Enter sub_str: ")
b=input("Enter sub_str: ")
n=int(input("Enter position to insert: "))
str1= a + str[:n] + b + str[n:]
print(str1)