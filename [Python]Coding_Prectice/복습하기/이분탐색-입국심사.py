#이분탐색 - 입국심사
#https://school.programmers.co.kr/learn/courses/30/lessons/43238

def solution(n, times):
    answer = 0
    times.sort()
    val_min = times[0]
    val_max = times[-1]*n
    
    while (val_min <= val_max):
        t = (val_min+val_max)//2
        people = sum([t//_t for _t in times])
        if people>=n:
            answer = t
            val_max = t-1
        elif people<n:
            val_min = t+1
    return answer
