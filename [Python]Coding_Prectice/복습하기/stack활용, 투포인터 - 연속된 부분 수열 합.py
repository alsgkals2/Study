#Stack활용, 투포인터 - 연속된 부분 수열 합
#코딩테스트 연습 - 연속된 부분 수열의 합 | 프로그래머스 스쿨 (programmers.co.kr)

def solution(sequence, k):
    start=0
    end=0
    sum_temp = sequence[start]
    candis = []
    answer = []
    len_seq = len(sequence)
    candis = ([],10000000)
    while start<len_seq:
        if end>len_seq:
            if start < len(sequence):
                sum_temp -= sequence[start]
            start+=1
            break
        # val= sum(sequence[start:end]) sum을 반복문에 넣으면 무조건 시간초과
        val = sum_temp
        if val == k:
            if end-1-start<candis[1]:
                candis=(([start,end], end-1-start))
            if start < len(sequence):
                sum_temp -= sequence[start] #원래 이때 sum_temp = sequence(start+1); end = start+1로 초기화해서 처음부터 end +1 해가면서 비교하려했는데, 그럴 필요가 없었음. 그냥 start위치만 빼서 쭉 진행하면 알아서 push, pop할 수 있었음.
            start+=1
        elif val < k:
            end+=1
            if end < len(sequence):
                sum_temp += sequence[end]
        else: #val이 큰경우
            if start < len(sequence):
                sum_temp -= sequence[start]
            start+=1
            
    answer = candis[0]
    return answer
