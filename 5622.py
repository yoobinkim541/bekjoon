word = ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']
text = input()
num = 0
for i in range(len(text)):
    for j in word:
        if text[i] in j:
            num += word.index(j)+3
print(num)