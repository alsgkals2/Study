#최단거리 구하기
#bfs로 접근해야함(for 문)
#https://school.programmers.co.kr/learn/courses/30/lessons/1844
import itertools
from collections import deque
answer = 10000*10000
dx = [(0,1),(1,0),(0,-1),(-1,0)]
def bfs(maps, visited, x,y, cnt):
    global answer
    queue = deque()
    queue.append((x,y))
    visited[x][y] = 0
    while queue:
        _x, _y = queue.popleft()
        if _x == len(visited)-1 and _y== len(visited[0])-1 and cnt < answer:
            answer = maps[_x][_y]
            return

        for ax, ay in dx:
            if (_x+ax >= len(visited) or _y+ay >= len(visited[0]) or _x+ax < 0 or _y+ay < 0):
                continue
            # print(_x, _y, ax, ay)
            if visited[_x+ax][_y+ay] == 1:
                visited[_x+ax][_y+ay] = 0
                maps[_x+ax][_y+ay] = maps[_x][_y]+1
                print(_x+ax,
                      _y+ay)
                queue.append((_x+ax, _y+ay))

    if maps[len(maps)-1][len(maps[0])-1] == 1:
        answer = -1
        
def solution(maps):
    global answer
    visited = [[m for m in _maps] for _maps in maps ]
    bfs(maps,visited,0,0,1)
    if answer == 10000*10000 :
        answer = -1
    return answer
