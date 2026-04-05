a,b =  input().split()
a = list(a)
b = list(b)
A = 0
B = 0
for i in range(len(a)):
    A += int(a[i])
for i in range(len(b)):
    B += int(b[i])
print(A*B)
 