N = int(input())
list_1 = list(map(int, input().split()))
list_2 = list(map(int, input().split()))

for i in range(N):
    if list_1[i] == 0 and list_2[i] == 0:
        print(0)
        break
    if i < N - 1:
        if (list_1[i] == 0 and list_2[i+1] == 0) or (list_2[i] == 0 and list_1[i+1] == 0):
            print(0)
            break
else: 

    if all(list_1) and all(list_2):
        print(2)
    else:
        print(1)
