# 뒤에있는 큰 수 구하기(다시 풀어보기 이해가 안됨..)
# https://school.programmers.co.kr/learn/courses/30/lessons/154539

def solution(numbers):
    answer = []
    stack = []
    answer = [-1 for i in range(len(numbers))]
    for i, ele in enumerate(numbers):
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
        stack.append(i)
        # answer.append(-1)
        
#         checklist = ([num>ele for num in numbers[i+1:]])
#         if sum(checklist) == 0:
#             continue
            
#         for n in numbers[i+1:]:
#             if n>ele:
#                 answer[-1] = n
#                 break
    return answer
