#https://school.programmers.co.kr/learn/courses/30/lessons/92335
#소수 구하기
def is_prime(k):
    if k == 1 : return False
    for i in range(2, int(math.sqrt(k))+1):
        if k % i == 0:
            return False
        
    return True


n을 k진법으로 변환
    while n > 0:
        n, mod = divmod(n, k)
        rev_base += str(mod)
    rev_base = rev_base[::-1] #list reversing