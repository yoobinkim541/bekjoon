sum = 0

while True:
    a = input()
    if a == "brown":
        sum = 1
    elif a == "red":
        sum = 2
    elif a == "orange":
        sum = 3
    elif a == "yellow":
        sum = 4
    elif a == "green":
        sum = 5
    elif a == "blue":
        sum = 6
    elif a == "violet":
        sum = 7
    elif a == "grey":
        sum = 8
    elif a == "white":
        sum = 9
    break

while True:
    a = input()
    if a == "black":
        sum = sum*10
    elif a == "brown":
        sum = sum*10 + 1
    elif a == "red":
        sum = sum*10 + 2
    elif a == "orange":
        sum = sum*10 + 3
    elif a == "yellow":
        sum = sum*10 + 4
    elif a == "green":
        sum = sum*10 +5
    elif a == "blue":
        sum = sum*10 +6
    elif a == "violet":
        sum = sum*10 +7
    elif a == "grey":
        sum = sum*10 +8
    elif a == "white":
        sum = sum*10 +9
    break

while True:
    a = input()
    if a == "black":
        sum = sum*1
    elif a == "brown":
        sum = sum*10
    elif a == "red":
        sum = sum*100
    elif a == "orange":
        sum = sum*1000
    elif a == "yellow":
        sum = sum*10000
    elif a == "green":
        sum = sum*100000
    elif a == "blue":
        sum = sum*1000000
    elif a == "violet":
        sum = sum*10000000
    elif a == "grey":
        sum = sum*100000000
    elif a == "white":
        sum = sum*1000000000
    break
print(sum)
    
