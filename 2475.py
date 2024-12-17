num = input().split()
sum = 0
for i in range(len(num)):
    sum += int(num[i])*int(num[i]) 
print(sum % 10)