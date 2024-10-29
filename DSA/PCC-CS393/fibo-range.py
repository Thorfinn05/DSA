def fibonacci(n):
  if(n<=1):
    return 1
  else:
    return fibonacci(n-1)+ fibonacci(n-2)

n=20
a=30
print('Fibpnacci series: ', end=' ')
for i in range (n):
  print(fibonacci(i),end=' ')
  if(i>a):
    break


