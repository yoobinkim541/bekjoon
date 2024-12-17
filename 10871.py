n,x = map(int,input().split())
list = list(map(int,input().split()))
result = 0
for i in range(n):
    if (list[i] < x):
        print(list[i])
