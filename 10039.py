num = 0
for i in range(5):
    a = int(input())
    if a >= 40:
        num += a
    else:
        num += 40
print(int(num/5))