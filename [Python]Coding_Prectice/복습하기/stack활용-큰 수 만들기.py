#큰수만들기
#https://school.programmers.co.kr/learn/courses/30/lessons/42883?language=python3#

from itertools import permutations, combinations #얘네 쓰면 시간초과남
def solution(number, k):
    list_candi = []
    answer = 0
    for _k in range(len(number)-k,0,-1):
        if -_k+1 != 0:
            _number = number[:-_k+1]
        else:
            _number = number #number[:0] 은 슬라이싱 되지않으므로 건너뒴
        if '9' in _number:
            idx_max = _number.find('9') #시간복잡도 줄이기위해
        else:
            idx_max = _number.find(max(_number))
        number = number[idx_max+1:]
        list_candi.append(_number[idx_max])
        # except:
    answer = (''.join(list_candi))  
    
#     candis = list(combinations([i for i in range(len(number))], len(number)-k))
#     for c in candis:
#         if number[c[0]] == 0:
#             continue
#         templist = [(number[c[i]]) for i in range(len(c))]
#         _num = int(''.join(templist))
#         if _num>answer:
#             answer = _num
            
#     answer = str(answer)

    return answer
