import collections
def solution(want, number, discount):
    answer = 0
    dict_want = {}
    for w, n in zip(want,number):
        dict_want[w] = n
        
    for i in range(len(discount)-9):
        swit = True
        dict_temp = (collections.Counter(discount[i:i+10]))
        if dict_temp == dict_want:
            answer += 1
        # for k, v in dict_temp.items():
        #     if not(k in dict_want and dict_want[k]==dict_temp[k]):
        #         swit = False
        #         break
        # if swit:
        #     answer += 1 
    
    return answer