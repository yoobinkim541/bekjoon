sentex = [['']*15 for i in range(5)]
for i in range(5):
    text = input()
    j = 0
    for j in range(len(text)):
        sentex[i][j] = text[j]
        j += 1
for i in range(15):
    for j in range(5):
        print(sentex[j][i],end = '')