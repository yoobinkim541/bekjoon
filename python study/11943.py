a = list((input().split()))
b = list((input().split()))
result = 0

a1 = int(a[0]) + int(b[1])
b1 = int(a[1]) + int(b[0])

if a1 > b1:
    result = b1
elif a1 == b1:
    result = b1
else:
    result = a1
print(result)