#주차요금계산 (str활용, dict활용)
#https://school.programmers.co.kr/learn/courses/30/lessons/92341

from datetime import datetime
from collections import OrderedDict
def solution(fees, records):
    answer = []
    dict_plat = {}
    for re in records:
        split_re = re.split(' ')
        if split_re[1] not in dict_plat:
            dict_plat[split_re[1]] = [split_re[0]]
        else:
            dict_plat[split_re[1]].append(split_re[0])
            
    dict_plat = OrderedDict(sorted(dict_plat.items(), key=lambda x: x[0], reverse=False))
    for plat in dict_plat.keys():
        _alltime = 0
        for i in range(0, len(dict_plat[plat]), 2):
            _in = dict_plat[plat][i]
            a= datetime.strptime(_in, '%H:%M')
            if len(dict_plat[plat]) > i+1:
                _out = dict_plat[plat][i+1]
            else:
                _out = '23:59'
            b= datetime.strptime(_out, '%H:%M')
            _alltime += ((b-a).seconds/60)
            
        if _alltime < fees[0]:
            cost = fees[1]
        else:
            m_a,m_b = divmod(_alltime-fees[0],fees[2])
            if m_b != 0 : m_a += 1
            cost = (int(fees[1] + fees[3]*m_a))
        answer.append(cost)
    return answer
