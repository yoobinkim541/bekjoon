dohuazi = [[0]*100 for i in range(100)]
colorpaper = int(input())
for i in range(colorpaper):
    x,y = map(int,input().split())
    for j in range(10):
        for o in range(10):
            dohuazi[x+o][y+j] += 1
count = 0
for i in range(100):
    for j in range(100):
        if dohuazi[i][j] > 0:
            count += 1
print(count)