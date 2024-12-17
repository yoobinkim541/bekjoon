list = [a for a in range(1,31)]
for i in range(28):
    data =  int(input())
    list.remove(data)
print(min(list))
print(max(list))
