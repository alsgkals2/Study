#dict 활용
#https://school.programmers.co.kr/learn/courses/30/lessons/42888

def solution(record):
    answer = []
    dict_name = {}
    list_print = []

   printer = {'Enter':'님이 들어왔습니다.', 'Leave':'님이 나갔습니다.'}

    for re in record:
        re_split = re.split(' ')
        if re_split[0] == 'Change' or re_split[0] == 'Enter':
            dict_name[re_split[1]] = re_split[2]

# 아래 주석을 이렇게 바꿔볼 수 있음
        if re_split[0] in ['Enter', 'Leave']:
            list_print.append(re_split[1]+ printer[re_split[0]])
“””
        if re_split[0] == 'Enter':
            list_print.append(re_split[1]+" 님이 들어왔습니다.")
        elif re_split[0] == 'Leave':
            list_print.append(re_split[1]+" 님이 나갔습니다.")
“””
            
    for out in list_print:
        id = out[:out.find(' ')]
        answer.append(out.replace(out[:out.find(' ')+1], dict_name[id]))
              
                    
    return answer
