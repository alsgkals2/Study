#heap 활용(자동정렬시켜줌)
​​#https://school.programmers.co.kr/learn/courses/30/lessons/42626#

import heapq
def is_all_fine(que,K):
    for i in range(len(que)):
        if que[i] < K:
            return False
    return True

def solution(scoville, K):
    answer = 0
    heap = []
    for _s in scoville:
        heapq.heappush(heap, _s)
        
    while heap[0] < K:
        temp_val = heapq.heappop(heap)
        if len(heap) > 0:
            val = temp_val + heapq.heappop(heap) * 2 
            heapq.heappush(heap,val)
            if len(heap) == 1 and heap[0] < K: #원소가 한개만 남았는데도 K미만일때
                return -1
        answer += 1
    
    return answer

