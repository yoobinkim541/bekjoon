name = list(input())
name.sort()
set_name = list(set(name))
set_name.sort()
count = 0
name_num = []
mid = ''
for i in set_name:
    count_name = name.count(i)
    name_num.append(count_name)
    if count_name % 2 != 0:
        count += 1
        mid = i  # 가운데 들어갈 문자 저장

if count > 1:
    print("I'm Sorry Hansoo")
else:
    left = ''
    for i in range(len(set_name)):
        n = name_num[i] // 2
        left += set_name[i] * n
    right = left[::-1]
    print(left + mid + right)