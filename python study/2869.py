# 올라가야 할 거리 v-b 하루에 올라가는 거리 a-b

a,b,v = map(int, input().split())

if((v-b) % (a-b) == 0):
    print((v-b)// (a-b))
else:
    print((v-b)//(a-b) + 1)