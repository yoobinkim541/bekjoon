while True:
    num = list(input())
    inverse = []
    for i in range(len(num)):
        inverse.append(num[len(num)-i-1])
    if num == ['0']:
        break
    elif num == inverse:
        print('yes')
    else:
        print('no')