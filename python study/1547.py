M = int(input())
result = 1

for i in range(M):
    X,Y = map(int,input().split())
    if X == result:
        result = Y
    elif Y == result:
        result = X
print(result)