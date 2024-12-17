text = list(input())
abc = 'abcdefghijklmnopqrstuvwxyz'
for i in abc:
    if i in text:
        print(text.index(i), end = ' ')
    else:
        print(-1, end = ' ')