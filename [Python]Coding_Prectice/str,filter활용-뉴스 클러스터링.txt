#뉴스 클러스터링
#https://school.programmers.co.kr/learn/courses/30/lessons/17677
#alphabet 요소로만 구성되게 필터시키기 list(filter(str.isaplha, list_variance))
import math
from itertools import combinations
def solution(str1, str2):
    answer = 0
    list_alphas = [(str1[al].lower()+str1[al+1].lower()) for al in range(len(str1)-1)]
    list_alphas2 = [(str2[al].lower()+str2[al+1].lower()) for al in range(len(str2)-1)]
    set_alpha = (list(filter(str.isalpha, list_alphas)))
    set_alpha2 = (list(filter(str.isalpha, list_alphas2))) -> filter, isalpha를 통해서 alphabet로만 구성된 요소를 남김
    temp_set_alpha = list(set(set_alpha) | set(set_alpha2))
    num_under = sum([max(set_alpha2.count(t),set_alpha.count(t)) for t in temp_set_alpha]) -> list에서 특정요소 갯수 구하기
    
    temp_set_alpha = list(set(set_alpha) & set(set_alpha2))
    num_upper = sum([min(set_alpha2.count(t),set_alpha.count(t)) for t in temp_set_alpha])

    if num_upper == 0 and num_under == 0 :
        answer = 65536
    else :
        answer = (math.trunc((num_upper/num_under)*65536))
    return answer

