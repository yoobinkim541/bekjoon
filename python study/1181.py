num = int(input())
text = set()

for i in range(num):
    a = input().strip()
    text.add(a)

text = list(text)
text.sort(key=lambda x: (len(x), x))

for t in text:
    print(t)

