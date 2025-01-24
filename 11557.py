textcase = int(input())
for i in range(textcase):
    u = int(input())
    S1 = "" 
    L1 = 0
    for o in range(u):
        S,L = input().split()
        L = int(L)
        if L > L1:
            S1 = S
            L1 = L
    print(S1)
