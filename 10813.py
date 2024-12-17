N,M = map(int, input().split())
basket = []
plate = []
for a in range(N+1):
    basket += [a]
for b in range(M):
    i,j = map(int, input().split())
    plate = basket[i]
    basket[i] = basket[j]
    basket[j] = plate
for c in range(1,len(basket)):
    print(basket[c], end = ' ')
