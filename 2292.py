N = int(input())
room = 1
result = 1

while N > room:
    room += 6*result
    result += 1
print(result)