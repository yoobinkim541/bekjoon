import sys
text = sys.stdin.readline().rstrip()
ppap = []
result = 'NP'

for i in text:
    ppap.append(i)
    if len(ppap) >= 4 and ppap[-4:] == ['P','P','A','P']:
        for o in range(3):
            ppap.pop()
if ppap == ['P']:
    result = 'PPAP'
print(result)



