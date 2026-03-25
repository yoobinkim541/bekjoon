num = int(input())
name = []

for i in range(num):
    age = list(input().split())
    name.append([int(age[0]),age[1]])
name.sort(key = lambda x: (x[0]))

for i in name:
    print(*i)