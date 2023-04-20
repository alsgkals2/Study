#플로이드와샬 - 순위
#https://school.programmers.co.kr/learn/courses/30/lessons/49191?language=python3#


def solution(n, results):
    answer = 0
    check = [[False for j in range(n)] for i in range(n)]
    for i,j in results:
        check[i-1][j-1] = True
    pprint.pprint(check)
        
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if check[j][i] and check[i][k] :
                    check[j][k] = True
    for i in range(n):
        if sum(check[i]) + sum([check[j][i] for j in range(n)]) >= n-1:
            answer += 1
                
    return answer
