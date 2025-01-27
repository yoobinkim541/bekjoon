N = int(input())
calltime = list(input().split())
price1 = 0
price2 = 0
for i in range(N):
    price1 += (int(calltime[i])//30+1)*10
    price2 += (int(calltime[i])//60+1)*15
if price1 == price2:
    print("Y","M",price1)
elif price1 < price2:
    print("Y",price1)
else:
    print("M",price2)