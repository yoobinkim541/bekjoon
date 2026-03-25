num = int(input())
abc = list('abcdefghijklmnopqrstuvwxyz')
text = list(input())
result = 0
buffer = 0
for i in range(num):
    for o in range(len(abc)):
        if text[i] == abc[o]:
            buffer = o+1
    result += buffer*31**i
result = result % 1234567891
print(result)
