N,B = input().split()
count = 0
multiply = 1
for i in N[::-1]:
    if '0' <= i <= '9':
        count += multiply*int(i)
    else:
        count += multiply*(ord(i)-ord('A')+10)
    multiply *= int(B)
print(count)