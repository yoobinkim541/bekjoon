N = int(input())
backup = max(1, N - 9 * len(str(N)))

for i in range(backup, N):
    result = i + sum(map(int, str(i)))
    if result == N:
        print(i)
        break
else:
    print(0)