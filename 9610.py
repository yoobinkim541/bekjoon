num = int(input())
Q1 = 0
Q2 = 0
Q3 = 0
Q4 = 0
AXIS = 0
for i in range(num):
    x,y = map(int, input().split())
    if (x == 0 or y == 0):
        AXIS += 1
    elif(x > 0 and y > 0):
        Q1 += 1
    elif(x < 0 and y > 0):
        Q2 += 1
    elif(x < 0 and y < 0):
        Q3 += 1
    elif(x > 0 and y < 0):
        Q4 += 1
print("Q1:",Q1)
print("Q2:",Q2)
print("Q3:",Q3)
print("Q4:",Q4)
print("AXIS:",AXIS)