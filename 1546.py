num = int(input())
score = list(map(int, input().split()))
maximum = max(score)
result = 0
for i in range(num):
    new_score = score[i]/maximum *100
    result += new_score
print(result/num)