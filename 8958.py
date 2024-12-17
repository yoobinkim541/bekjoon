num = int(input())

for i in range(num):
    score, c = 0,1
    anser = list(input())
    for j in anser:
        if j == "O":
            score += c
            c += 1
        else:
            c = 1
    print(score)
