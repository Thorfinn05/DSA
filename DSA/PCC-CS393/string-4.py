#Write a python program to print index of nth occurrence of a substring in a string.
str="123456789aabcadabcdabc"
sub="ab"
n=int(input("Enter no. of occurance: "))
indx=-1
c=0
for i in range (1, n+1):
  print(f"{sub} search from index {indx+1} to {len(str)} and found at",end=" ")
  indx=str.find(sub, indx+1, len(str))
  print(f"{indx} and occurance no. is {i}")
  c=c+1
  if(indx==-1):
    print(f"{sub} does not have {n}th occurance in {str}.")
    break
if(indx!=-1):
  print(f"{sub} has {str.count(sub)} many occurance in given {str}")


