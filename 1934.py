from math import gcd

num = int(input())
for i in range(num):
    a,b = map(int, input().split())
    print(a*b//gcd(a,b))