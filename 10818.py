a = int(input())
list = list(map(int,input().split()))
max = -1000000
min = 1000000
for i in range(a):
    if(max <= list[i]):
        max = list[i]
    if(min >= list[i]):
        min = list[i]
print(min)
print(max)


    