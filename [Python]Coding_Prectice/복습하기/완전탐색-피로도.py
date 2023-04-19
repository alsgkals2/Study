#완전탐색
#https://school.programmers.co.kr/learn/courses/30/lessons/87946

import copy

answer = 0 
def search_dun(k, dungeons, cnt):
    global answer
    _dungeons = copy.deepcopy(dungeons)
    for dun in _dungeons:
        if dun[0] <= k and dun[0] != -1:
            temp = dun[0]
            dun[0] = -1
            search_dun(k-dun[1], _dungeons, cnt+1)
            dun[0] = temp
    if answer < cnt:
        answer = cnt
            
def solution(k, dungeons):
    search_dun(k, dungeons, 0)            
    return answer
