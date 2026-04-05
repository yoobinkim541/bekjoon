num = int(input())
# 대각선 번호 = 대각선 원소의 수
# 홀수 대각선 >> 분자 : 대각선 번호 - 원소 번호 / 분모 :  1 + 원소 번호
# 짝수 대각선 >> 분자 : 1 + 원소번호 / 분모 : 대각선 번호 - 원소 번호
n = 1
while num > n*(n+1)//2:
    n += 1
index = num - n*(n-1)//2 - 1
if n % 2 == 0:
    print(f"{1 + index}/{n - index}")
else:
    print(f"{n - index}/{1 + index}")