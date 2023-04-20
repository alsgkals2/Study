def solution(price, money, count):
    answer = -1
    # 3 + 3*2 + 3*3 + 3*4
    answer = price * ((count*(count+1))//2) -money
    if answer<0:
        answer = 0
    
    return answer
