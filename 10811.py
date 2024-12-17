N,M = map(int, input().split())
list = [a for a in range(1,N+1)]

for b in range(M):
    i,j =  map(int, input().split())
    temp = list[i-1:j]
    temp.reverse()
    list[i-1:j] = temp
for c in range(N):
    print(list[c], end = ' ')
    