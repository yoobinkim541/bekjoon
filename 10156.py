k,n,m = map(int, input().split())
cost = 0
result = 0
cost = k*n
result = cost - m
if result <= 0:
    print(0)
else:
    print(result)