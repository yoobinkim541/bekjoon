num = int(input())
for i in range(num):
    cent = int(input())
    quarter = cent//25
    cent = cent%25
    dime = cent//10
    cent = cent%10
    nickel = cent // 5
    cent = cent%5
    penney = cent
    print(quarter,dime,nickel,penney)

    