N = int(input())
output = 0

for i in range(N):
    r,e,c = map(int, input().split())
    if r < e-c:
        print("advertise")
    elif r == e-c:
        print("does not matter")
    elif r > e-c:
        print("do not advertise")