#자물쇠와 열쇠 - 시뮬레이션(구현), array회전
#https://school.programmers.co.kr/learn/courses/30/lessons/60059
def rotate(key):
    n = len(key)
    m = len(key[0])
    new = [[0] * n for _ in range(m)]
    for i in range(n):
        for j in range(m):
            new[j][n-i-1] = key[i][j]
    return new

def checklock(lock,n):
    for i in range(n):
        for j in range(n):
            if lock[n+i][n+j] != 1:
                return False
    return True
def check(arr, N):
    answer = True
    for ix in range(N):
        for iy in range(N):
            if arr[ix + N][iy + N] != 1:
                return False
    return answer

def checking(pad_lock, key, n):                
    import copy
    #lock 순차적으러 검색
    #처음에 range(n,n*2)로 해서,, 자꾸 통과못했음.
    # key에서 오른쪽만 잘릴걸 시뮬레이션 하고있었는데 생각해보니 왼쪽도 잘릴 수 있었음.
    #최소 1행 or 1열부터 탐색해줘야 lock부분에 걸치게됨.
    
    #lock array 탐색
    for i in range(1,n*2):
        for j in range(1,n*2):
            #key값 비교
            for s_y in range(len(key)):
                for s_x in range(len(key[0])): 
                    pad_lock[i+s_y][j+s_x] += key[s_y][s_x]
            if check(pad_lock, n):
                return True
            
            for s_y in range(len(key)):
                for s_x in range(len(key[0])): 
                    pad_lock[i+s_y][j+s_x] -= key[s_y][s_x]
    return False

def solution(key, lock):
    answer = True
    len_lock = len(lock[0])
    answer = False
    #padding된 array 생성
    pad_lock = [[0 for j in range(len_lock*3)] for i in range(len_lock*3)]
    for i in range(len_lock):
        for j in range(len_lock):
            pad_lock[len_lock+i][len_lock+j] = lock[i][j]
    for _ in range(4):
        if checking(pad_lock, key, len_lock):
            return True
        key = rotate(key)
    return answer
