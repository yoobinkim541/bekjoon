two_dimention_list = []
for o in range(9):
    first_dimention_list = list(input().split())
    two_dimention_list.append(first_dimention_list)
# 완전탐색
max = 0
max_i = 0 
max_j = 0
for i in range(9):
    for j in range(9):
        num = int(two_dimention_list[i][j])
        if num > max:
            max = num
            max_i = i
            max_j = j
print(max)
print(max_i+1,max_j+1)
        

