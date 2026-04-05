x,y,h,w = map(int, input().split())
print(min(x,y,h-x,w-y))