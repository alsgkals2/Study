#사탕게임 (프루트포스)
#https://www.acmicpc.net/problem/3085


def sequence(arr, n): #max(열기준 cnt 최대값, 행기준 cnt 최대값)
    #low
    max_cnt = 0
    for i in range(n):
        cnt = 1
        for j in range(n-1):
            if arr[i][j] == arr[i][j+1]:
                cnt+=1
                max_cnt = max(cnt, max_cnt)
            else:
                cnt=1
        max_cnt = max(cnt, max_cnt)

    #col
    for i in range(n):
        cnt = 1
        for j in range(n-1):
            if arr[j][i] == arr[j+1][i]:
                cnt+=1
                max_cnt = max(cnt, max_cnt)
            else:
                cnt=1

        max_cnt = max(cnt, max_cnt)
    return max_cnt
            

def solution():
    n = int(input())
    inp= [input() for i in range(n)]
    inp = [list(st) for st in inp]
    max_num = 0
    
    #안바꿨을때에 대해 전체체크
    max_num = max(max_num,sequence(inp, n))

    for m_i in range(n):
        for m_j in range(n-1):
                if inp[m_i][m_j] != inp[m_i][m_j+1]:
                    inp[m_i][m_j+1], inp[m_i][m_j] = inp[m_i][m_j], inp[m_i][m_j+1]
                    max_num = max(max_num,sequence(inp, n))
                    inp[m_i][m_j+1], inp[m_i][m_j] = inp[m_i][m_j], inp[m_i][m_j+1] #다시 돌려둠
                    if max_num == n:
                        print(max_num)
                        return
    for m_i in range(n-1):
        for m_j in range(n):
                if inp[m_i][m_j] != inp[m_i+1][m_j]:
                    inp[m_i+1][m_j], inp[m_i][m_j] = inp[m_i][m_j], inp[m_i+1][m_j]
                    max_num = max(max_num,sequence(inp, n))
                    inp[m_i+1][m_j], inp[m_i][m_j] = inp[m_i][m_j], inp[m_i+1][m_j]
                    if max_num == n:
                        print(max_num)
                        return
    print(max_num)

solution()
