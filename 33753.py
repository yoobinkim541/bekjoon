a,b,c = map(int, input().split())
t = int(input())
cost = 0

if t <= 30:
    print(a)

else:
    cost = a
    t -= 30

    if t == 0:
        print(cost)

    elif t%b == 0:
        cost += (t//b)*c
        print(cost)

    else:
        cost += (t//b + 1)*c
        print(cost)