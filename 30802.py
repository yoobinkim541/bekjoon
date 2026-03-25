import sys
input = sys.stdin.readline

# 입력 받기
N = int(input())
sizes = list(map(int, input().split()))
T, P = map(int, input().split())

# 티셔츠 묶음 계산
tshirt_bundles = 0
for size in sizes:
    if size == 0:
        continue
    tshirt_bundles += (size + T - 1) // T

# 펜 묶음 계산
pen_bundles = N // P
pen_individuals = N % P

# 결과 출력
print(tshirt_bundles)
print(pen_bundles, pen_individuals)