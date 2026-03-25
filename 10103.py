num =  int(input())
c = 100
s = 100
for i in range(num):
    a,b = map(int, input().split())
    if (a > b):
        s = s - a
    if(a < b):
        c = c - b
print(c)
print(s)
