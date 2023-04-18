#소수 찾기
#https://school.programmers.co.kr/learn/courses/30/lessons/42839

from itertools import permutations, product, combinations
import math
def is_alone(num):
    for i in range(2,int(math.sqrt(num))+1):
        if num%i == 0:
            return False
    return True
            
def solution(numbers):
    answer = 0
    list_perm = []
    for i in range(1,len(numbers)+1):
        list_perm = list_perm + (list(permutations(numbers, i))) #1자릿수~len(numbers)자릿수까지 모든 경우의수 list에 저장 
    set_perm = filter(lambda x:x>1, list(set([int(''.join(ele)) for ele in list_perm]))) #0,1는 소수 후보군에서 뺌, set을 통해 중복제거 + int변경을 통해 0으로 시작하는 숫자 제거
    for candi in set_perm:
        answer = answer+1 if is_alone(candi) else answer
    return answer


