#주식가격
#https://school.programmers.co.kr/learn/courses/30/lessons/42584#

def solution(prices):
    answer = []
    list_len = []
    answer = list(range(len(prices)))[::-1]
    for idx, ele in enumerate(prices): 
        _input=answer[idx]
        for i in range(idx+1, len(prices)):
            if prices[i] < ele:
                _input = i-idx
                break
        list_len.append(_input)
    answer = list_len
    # list_len = [list(filter(lambda x: x<prices[i],prices[i:])) for i in range(len(prices))]
    # for i in range(len(answer)):
        # answer[i] = answer[i] - list_len[i][0]
    # answer = [answer[i] - list_len[i][0] if list_len[i] else 0 for i in range(len(answer))]
    return answer
