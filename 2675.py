num = int(input())
for i in range(num):
    N,S = map(str,input().split())
    N = int(N)
    S = list(S)
    for j in range(len(S)):
        print(S[j]*N, end = '')
    print('')