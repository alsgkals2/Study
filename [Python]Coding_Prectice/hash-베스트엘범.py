#해시 - 베스트엘범
#https://school.programmers.co.kr/learn/courses/30/lessons/42579#


from collections import defaultdict
from collections import OrderedDict
def solution(genres, plays):
    answer = []
    temp_dict = defaultdict()
    dict_sum = []
    for i in range(len(plays)):
        if not genres[i] in temp_dict:
            temp_dict[genres[i]] = []
        temp_dict[genres[i]].append((plays[i], i))
        
    for i in temp_dict.keys():
        temp_dict[i] = sorted(temp_dict[i],key = lambda x:(-x[0], x[1]))
        dict_sum.append((i,sum([temp_dict[i][j][0] for j in range(len(temp_dict[i]))])))
    dict_sum.sort(key=lambda x: x[1],reverse=True)
    for name, val in dict_sum:
        [answer.append(temp_dict[name][i][1]) for i in range(min(2, len(temp_dict[name])))]
    return answer
