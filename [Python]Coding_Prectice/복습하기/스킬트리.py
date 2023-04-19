#스킬트리
#https://school.programmers.co.kr/learn/courses/30/lessons/49993#
#반드시 선행스킬이 학습돼야한다는 전제로 진행됨. 즉 skill[-1]은 트리에서 빠질수 있지만 skill[0]이 빠질 순 없음. 빠지려면 모든 skill항목이 빠져있어야함

def solution(skill, skill_trees):
    answer = 0
    
    for tree in skill_trees:
        alpha= []
        for s in skill:
            idx = tree.find(s)
            if idx != -1:
                alpha.append(idx)
        alpha = sorted(alpha)
        if ''.join([tree[i] for i in alpha]) == skill[:len(alpha)]:
            answer+=1
    
    return answer


