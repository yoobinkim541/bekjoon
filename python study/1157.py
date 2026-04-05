text = input().lower()
text_list = list(set(text))
count = []

for i in text_list:
    count1 = text.count(i)
    count.append(count1)

if count.count(max(count)) >= 2:
    print("?")
else:
    print(text_list[(count.index(max(count)))].upper())