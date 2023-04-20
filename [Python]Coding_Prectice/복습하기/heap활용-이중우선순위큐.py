#힙(heap)- 이중우선순위큐
#https://school.programmers.co.kr/learn/courses/30/lessons/42628#
#https://jungeun960.tistory.com/146 (최대힙참고)

from collections import OrderedDict
import heapq
def solution(operations):
    answer = []
    dic = OrderedDict()
# heapq에는 reverse시키는 함수가 따로없어서 max_temp에 (-num,num)으로 구성시켜 -num 순으로 sorting시키도록 하는게 포인트
    temp = []
    max_temp = []
    for op in operations:
        op = op.split(' ')
        if op[0] == 'D':
            if op[-1] == '1' and max_temp:
                val = heapq.heappop(max_temp)
                temp.remove(val[1])
            elif op[-1] == '-1' and temp:
                val = (heapq.heappop(temp))
                max_temp.remove((-val, val))
        elif op[0] == 'I':
            heapq.heappush(temp, (int(op[-1])))
            heapq.heappush(max_temp, (-int(op[-1]), int(op[-1])))
    if not max_temp and not temp:
        answer = [0,0]
    else:
        answer = [max_temp[0][1], temp[0]]
    return answer
