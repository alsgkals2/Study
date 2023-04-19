#구현 - 경사로
#https://www.acmicpc.net/problem/14890
M, L= map(int,input().split())
arr = []
[arr.append(list(map(int, input().split()))) for i in range(M)]


answer= 0
temp = []
arr_ro = list(map(list,zip(*arr[::-1]))) #세로방향, 가로방향 두개 보기위해서 90도회전한 array
for _arr in [arr, arr_ro]:
    for line in _arr:
        _temp = []
        s = 0
        start = line[s]
        cnt = 0
        for i in range(len(line)):
            if start == line[i]:
                    cnt += 1
            else:
                _temp.append((start, cnt))
                s = i
                start = line[s]
                cnt = 1
        _temp.append((start,cnt))
        temp.append(_temp)

        
#연속된 숫자들 묶어서 (높이, count) 튜플로 다시 만들기
answer= 0
temp = []
arr_ro = list(map(list,zip(*arr[::-1])))
for _arr in [arr, arr_ro]:
    for line in _arr:
        _temp = []
        s = 0
        start = line[s]
        cnt = 0
        for i in range(len(line)):
            if start == line[i]:
                    cnt += 1
            else:
                _temp.append((start, cnt))
                s = i
                start = line[s]
                cnt = 1
        _temp.append((start,cnt))
        temp.append(_temp)
#높이는 0~1차이만 나야하므로 2이상인 애들 미리 filter
for t in range(len(temp))
    operation = range(len(temp[t])-1)
    for i in operation:
        if abs(temp[t][i+1][0]-temp[t][i][0]) != 1:
            temp[t] = []
            break



#예외상황을 많이 고려해야했음..
#첫번째 if문 - 현재 높이가 양옆 높이보다 낮은경우
#두번째, 네번째 if문 - 현재 높이보다 오른쪽 or 왼쪽높이가 높은경우
#세번째 if문 - 양쪽높이가 현재보다  낮은 경우가 아님에도 불구하고 현재 길이가 L보다 작은경우
for idx in range(len(temp)):
    if not temp[idx] :
        continue
    for i in range(len(temp[idx])):
        if (i-1>=0 and i+1<len(temp[idx])) and\
            temp[idx][i][0]<temp[idx][i-1][0] and \
            temp[idx][i][0]<temp[idx][i+1][0] and\
            temp[idx][i][1]//2 < L:
            temp[idx] = []
            break
      
        elif i+1<len(temp[idx]) and\
            temp[idx][i][1] < L and temp[idx][i+1][0]>temp[idx][i][0]:
            temp[idx] = []
            break
        elif (i-1>=0 and i+1<len(temp[idx])) and\
            temp[idx][i][1] < L and not (temp[idx][i+1][0] < temp[idx][i][0] and\
            temp[idx][i-1][0] < temp[idx][i][0]):
            temp[idx] = []
            break
        elif i-1>=0 and \
            temp[idx][i][1] < L and temp[idx][i-1][0] > temp[idx][i][0]:
            temp[idx] = []
            break
            
answer += len(list(filter(lambda x:x,temp)))
print(answer)
        
