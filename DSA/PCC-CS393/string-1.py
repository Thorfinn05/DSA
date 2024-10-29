#Write a python program to get a single string from two given strings, separated by a space and swap the first two characters of each string.
str1="Gemlo"
str2="Hemlo"
str_new = str2[0] + str1[1:] + " " + str1[0] + str2[1:]
print(str_new)
str3="Goja"
str4="Bhaja"
str__new= str4[0] + str3[1:3] + str4[1] + " " + str3[0] + str4[2:4] + str3[1]
print(str__new)
