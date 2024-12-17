num = input().split()
asc  = [str(i) for i in range(1,9)]
dec = asc[::-1]
if(num == asc):
    print('ascending')
elif(num == dec):
    print('descending')
else:
    print('mixed')
