num = list(input().split())
n1 = num[0][::-1]
n2 = num[1][::-1]
result = int(n1)+int(n2)
result = str(result)[::-1]
print(int(result))