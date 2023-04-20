
다익스트라 활용 (왔다갔다 시간 최소화) - 파티
https://www.acmicpc.net/problem/1238
https://nkw011.github.io/baekjoon/baekjoon-1238/#12-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-tip ->개선방법


from collections import deque
answer = 0
n,m,x = list(map(int,input().split()))
dist = [[0 for i in range(n)] for j in range(n)]
nodes = []
for _ in range((m)):
    nodes.append(list(map(int,input().split())))
dict_node = {}
for i in range(len(nodes)):
    if not nodes[i][1] in dict_node:
        dict_node[nodes[i][1]] = []
    dict_node[nodes[i][1]].append((nodes[i][0], nodes[i][2]))

dist = [0 for _ in range(n+1)]
queue = deque(dict_node[x])
_dist = 0
cnt = 0
checkpoint = [False for _ in range(n+1)]
checkpoint[x] = True
list_dist = [[] for _ in range(n+1)]

# 여기서 포인트는 x,노드i간의 최단거리 계산 뿐만 아니라, 노드i에 대해서 x로의 최단거리를 계산해서 노드i,x + x,노드i 간의 최단거리를 구해야하는 것임
for z in range(1,n+1): 
    dist = [999999999 for _ in range(n+1)]
    queue = deque(dict_node[z])
    cnt = 0
    # checkpoint = [False for _ in range(n+1)]
    # checkpoint[x] = True
    for no in queue:
        dist[no[0]] = no[1]
    while queue:
        cnt+=1
        node = queue.popleft()
        s, node_dist = node[0], node[1]
        # if checkpoint[s] == True:
            # continue
        # checkpoint[s] = True
        for no in dict_node[node[0]]:
            if dist[no[0]] > node_dist+no[1]:
                dist[no[0]] = node_dist+no[1]
                queue.append((no[0], dist[no[0]]))
    list_dist[z] = dist
list_ans = []
for i in range(1,n+1):
    list_ans.append(list_dist[i][x]+list_dist[x][i])
list_ans[x-1] = 0
print(max(list_ans))
