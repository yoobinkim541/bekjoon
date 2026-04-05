num = int(input())
for i in range(num):
    print(" "*i, end = '')
    print("*"*((num-i)*2 - 1))

for j in range(1,num):
    print(" "*(num-j - 1), end = '')
    print("*"*(j*2+1))