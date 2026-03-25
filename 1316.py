N = int(input())
result = []
set_result = []
num = 0

for i in range(N):
    text = list(input())
    if len(text) == 1:
        result.append(text[0])
    for o in range (len(text)-1):
        
        if o == 0:
            if text[o] != text[o+1]:
                result.append(text[o])
                result.append(text[o+1])
            elif text[o] == text[o+1]:
                result.append(text[o+1])
        else:
            if text[o] != text[o+1]:
                result.append(text[o+1])

    result.sort()
    set_result = list(set(text))
    set_result.sort()

    if result == set_result:
        num += 1
        result = []
    else:
        result = []

print(num)
            
