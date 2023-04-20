#두 큐 합 같게
#https://school.programmers.co.kr/learn/courses/30/lessons/118667#

#https://velog.io/@isayaksh/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Programmers-%EB%91%90-%ED%81%90-%ED%95%A9-%EA%B0%99%EA%B2%8C-%EB%A7%8C%EB%93%A4%EA%B8%B0-Python

#split() / split(“ “)차이 -> ‘a   b’ =>[‘a’ , ‘b’] / [‘a’, ‘’, ‘’, ‘b’]

from collections import deque
import copy
def solution(queue1, queue2):
    answer = 0
    queue1 = deque(queue1)
    queue2 = deque(queue2)
#매번 sum 함수 돌면 시간복잡도 확늘어남! sum값을 따로 만들어두기
    sum_queue1 = sum(queue1)
    sum_queue2 = sum(queue2)
    cnt=0
    # while cnt != 3:
#포인트는 3번루프 도는거임, 왼쪽으로 다 갔다가 오른쪽으로 다 가도록
    for _ in range(len(queue1)*3): 
        if sum_queue1>sum_queue2:
            v = queue1.popleft()
            queue2.append(v)
            sum_queue2+=v
            sum_queue1-=v
            answer+=1
        elif sum_queue1<sum_queue2:
            v = queue2.popleft()
            queue1.append(v)
            sum_queue1 += v
            sum_queue2 -= v
            answer += 1
        elif sum_queue1==sum_queue2:
            return answer
    return -1


