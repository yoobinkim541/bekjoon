N,m,M,T,R = map(int, input().split())
time = 0
hr = m
if M-m < T:
        print(-1)
else:
    while True:
        if N == 0:
            break

        elif hr + T <= M:
            hr += T
            N = N - 1
        
        elif m <= hr - R:
            hr -= R
            
        elif m > hr - R:
           hr = m
        time += 1
    print(time)