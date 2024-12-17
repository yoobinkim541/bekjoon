num = []
for a in range(10):
    list = int(input())
    if list % 42 not in num:
        num.append(list % 42)

print(len(num))


