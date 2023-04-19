#https://school.programmers.co.kr/learn/courses/30/lessons/42747
def solution(citations):
    answer = 0
    citations = sorted(citations,reverse=True)
    for i in range(len(citations),0,-1):
        _val = sum(list(citations[_i] >= _i+1 for _i in range(i)))
        if _val == i:
            answer = _val; return answer
    return answer
