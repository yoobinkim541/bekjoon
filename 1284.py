while True:
    N = list(input())
    if N == ['0']:
        break
    else:
        sum = 0
        for i in range(len(N)):
            if N[i] == '1':
                sum += 3
            elif N[i] == '0':
                sum += 5
            else:
                sum += 4
        sum += 1
    print(sum)
