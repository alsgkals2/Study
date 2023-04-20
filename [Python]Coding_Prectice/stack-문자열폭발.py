
#Stack활용 - 문자열 폭발 (네이버기출 유사)
#https://www.acmicpc.net/problem/9935
#포인트는 stack 활용 ! string에서 remove, join, replace 등을 쓰면 시간초과남
a = input()
b = input()
ans = ''
stack = []
len_b = len(b)
list_b = list(b)
for _a in a:
    stack.append(_a)  
#remove, replace 등을 쓰지않고 stack을 활용게 포인트임.시간복잡도를 줄임
    if stack[-len_b:] == list_b:
        [stack.pop() for _ in range(len_b)]
ans = ''.join(stack)

if ans == '' :
    print("FRULA")
else :
    print(ans)
