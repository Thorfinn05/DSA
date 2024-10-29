def chkPrime(n):
  c=0
  if(n>1):
    for i in range (2,(n//2)+1):
      if(n%i==0):
        c+=1
    if(c==0):
      return 1
    
beg=int(input('Enter beggining number: '))
end=int(input('Enter ending number: '))
print('Prime numbers from',beg,'to',end,'are: ')
for i in range (beg, end+1):
  if(chkPrime(i)==1):
    print(i,end=' ')