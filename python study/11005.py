a,b = map(int,input().split())
left_num = 0
arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
result = ''
while a:
    result += str(arr[a%b])
    a = a//b    

print(result[::-1])