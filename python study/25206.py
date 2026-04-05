a = []
for i in range(20):
    b = list(input().split())
    a.append(b)
sum_grade = 0
count = 0
for i in range(20):
    classscore = float(a[i][1])
    grade = a[i][2]
    if grade == "A+":
        sum_grade += classscore*4.5
        count += classscore
    elif grade == "A0":
        sum_grade += 4.0*classscore
        count += classscore
    elif grade == "B+":
        sum_grade += 3.5*classscore
        count += classscore
    elif grade == "B0":
        sum_grade += 3.0*classscore
        count += classscore
    elif grade == "C+":
        sum_grade += 2.5*classscore
        count += classscore
    elif grade == "C0":
        sum_grade += 2.0*classscore
        count += classscore
    elif grade == "D+":
        sum_grade += 1.5*classscore
        count += classscore
    elif grade == "D0":
        sum_grade += 1.0*classscore
        count += classscore
    elif grade == "F":
        sum_grade += 0*classscore
        count += classscore
result = sum_grade / count
print(f"{result :.6f}")



    