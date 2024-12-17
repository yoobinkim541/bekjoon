a =  int(input())
text = list(str(input()))
b = text.count('A')
c = text.count('B')
if b > c:
    print("A")
elif b == c:
    print("Tie")
elif b < c:
    print("B")