while True:
    a,b,c = map(int, input().split())
    if a == 0:
        break
    elif a > b and a > c:
        if a*a == (b*b+c*c):
            print('right')
        else:
            print('wrong')
    elif b > a and b > c:
        if b*b == (a*a + c*c):
            print('right')
        else:
            print('wrong')
    elif c > b and c > a:
        if c*c == (a*a + b*b):
            print('right')
        else:
            print('wrong')
    