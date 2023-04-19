#해시 - 다시풀어보기
#https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=python3
#→포인트는 dict를 쓰는거임

def solution(phone_book):
    answer = True
    dict_phone = {}
#미리 dict에 저장
    for p in phone_book:
        dict_phone[p] = 1
    for p in phone_book:
        temp = ''
        for str_p in p:
            if str_p in p :
                temp += str_p
            if temp in dict_phone and temp != p:
                return False
            
    return answer
