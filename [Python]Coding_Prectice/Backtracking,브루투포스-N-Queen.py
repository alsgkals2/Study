#n-queen (backtracking, 브루트포스)
#https://www.acmicpc.net/problem/9663
#Point : 2차 배열이 아닌 1차배열로 arr[열idx] = 행idx로 업데이트 +
#available함수상에서 진행해온 열 범위 내에서만 검사하는부분

n = int(input())
board = [-10000 for _ in range(n)]
ans = 0
def available(arr, x, y):
    global n
    for i in range(y):
        if i ==y : continue
        temp = abs(i-y)
        if (arr[i] == x or (abs(x-arr[i]) == abs(i-y))):
            return False
    return True

def dfs(board, cnt, s):
    global ans
    global n
    global temp
    
    if cnt == n:
        ans += 1
    if s>=n:
        return
    for i in range(len(board)):
        board[s] = i
        if available(board,i,s):
            dfs(board,cnt+1,s+1)
                
cnt = 0
dfs(board, 0, 0)
print(ans)
