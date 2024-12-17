N,M = map(int,input().split())
list = [0]*(N+1)
for a in range(M):
    x,y,i = map(int,input().split())
    for b in range(x,y+1):
        list[b] = i
for c in range(1,len(list)):
    print(list[c], end=' ')

