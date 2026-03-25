N  = int(input())
a = []
b = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
c = []
d = 0
for i in range(N):
    player = list(input())
    a += player[0]

for i in b:
    d = a.count(i)
    if d >= 5:
        c += i
if c == []:
    print('PREDAJA')
else:
    for i in c:
        print(i,end='')
