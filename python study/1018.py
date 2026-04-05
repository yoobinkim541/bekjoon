N,M = map(int,input().split())
min_result = 64
start = ''
chessboard = []
for i in range(N):
    arr = input()
    chessboard.append(arr)
for i in range(N-7):
    for j in range(M-7):
        w_count = 0
        b_count = 0
        for x in range(8):
                for y in range(8):
                    current = chessboard[i + x][j + y]
                    if (x + y) % 2 == 0: # WBWBWBWB BWBWBWBW WBWBWBWB BWBWBWBW
                        if current != 'W': 
                             w_count += 1
                        if current != 'B': 
                            b_count += 1
                    else:
                        if current != 'B': 
                             w_count += 1
                        if current != 'W': 
                             b_count += 1
        min_result = min(min_result, w_count, b_count)
print(min_result)
                                          

    
            
        
