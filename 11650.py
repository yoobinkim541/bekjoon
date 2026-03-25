n = int(input())
xy = []
for i in range (n):
    dot = list(map(int,input().split()))
    xy.append(dot)
xy.sort()
for i in range(len(xy)):
    print(*xy[i],end='\n')