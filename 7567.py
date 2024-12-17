text = list(map(str,input()))
hight = 10
i = 0

for i in range(len(text)-1):
    if text[i] == text[i+1]:
        hight += 5
        i += 1
    else:
        hight += 10
print(hight)