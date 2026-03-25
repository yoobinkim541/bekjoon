n = int(input())
for _ in range (0, n):
    A = list(map(str ,input().split()))
    result = float(A[0])
    for i in range (1, len(A)):
        if A[i] == '@': result *= 3
        elif A[i] == '%': result += 5
        elif A[i] == '#': result -= 7
    print("{:.2f}".format(result))