num = list(input().split())
a = list('112228')
text = []
for i in range(len(num)):
    b = 1 - int(num[i])
    text += str(b)
print(text)