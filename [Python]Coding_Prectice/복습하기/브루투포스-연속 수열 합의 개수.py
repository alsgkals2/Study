#연속 수열 합의 개수
#https://school.programmers.co.kr/learn/courses/30/lessons/131701

#개선된 코드 -> set에 add하는 순서를 i블럭단위로 순회한다음에 i+1블럭으로 늘리는 방식에서 a번째 위치에서 i~len(elements)까지 늘리면서 sum한다음에 a위치 +1 업데이트
def solution(elements):
    answer = 0
    temp_set = set()
    len_ele = len(elements)
    elements = elements * 2 # % 이용해서 나머지값들 처리하는거랑 시간차이가 크게있진 않은듯
    
    for i in range(len_ele):
        sum = elements[i]
        temp_set.add(sum)
        for j in range(i+1, i+len_ele):
            sum += elements[j]
            temp_set.add(sum)
    answer = len(temp_set)
    return answer

#시간 복잡도 확늘어남
# def solution(elements):
#     answer = 0
#     cnt = 0
#     temp_set = set()
#     len_ele = len(elements)
#     elements = elements * 2
#     start = 0
#     while cnt != (len_ele):
#         if start == 0:
#             cnt+=1
#             end = cnt
#         val_sum = sum(elements[start:end])
#         temp_set.add(val_sum)
#         start = (start+1)%len_ele
#         end +=1
#     answer = len(temp_set)
#     return answer
