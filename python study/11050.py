# nCk 는 (n*n-1*n-2.....)k개 / k!
n,k = map(int,input().split())
result = 1
for i in range(k):
    result *= n-i
packtorial = 1
for k in range(1,k+1):
    packtorial *= k
print(result // packtorial)