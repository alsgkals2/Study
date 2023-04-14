// War.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#define NCARDS 52
#define NSUITS 4
using namespace std;
const int QUEUESIZE = 52;

char values[] = "23456789TJQKA";
char suits[] = "cdhs";

typedef struct {
	int q[QUEUESIZE + 1];
	int first;
	int last;
	int count;
} qqq;

class Queue {
public:


	void init_queue(qqq *q) {
		q->first = 0;
		q->last = QUEUESIZE - 1;
		q->count = 0;
	}
	void enqueue(qqq *q, int x) {
		if (q->count >= QUEUESIZE) { cout << "Warning: queue overflow enqueue x=%d\n" << endl; }
		else {
			q->last = (q->last + 1) % QUEUESIZE;//last값 증가(최대사이즈 못넘게 %연산
			q->q[q->last] = x;//last위치에 x값을 넣는다.
			q->count = q->count + 1; //빈공간이 1칸 줄었으므로 마이너스 연산
		}
	}
	
	int dequeue(qqq *q) {
		int x=0;
		if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
		else {
			x = q->q[q->first];//반환할 값 미리 x에 저장
			q->first = (q->first + 1) % QUEUESIZE;
			q->count = q->count - 1;
		}

		return x;
	}

	int empty(qqq *q) {
		if (q->count <= 0) return 0;//비어있으면
		else return 1;//안비어있으면
	}
	void clear_queue(qqq*a, qqq*b)
	{
		while (!empty(a)) enqueue(b, dequeue(a));
	}


	int rank_card(char, char);
	char suit(int);
	char value(int);
	void war(qqq*, qqq*);
};

int Queue::rank_card(char value, char suit) {
	int i, j;
	for (i = 0; i < (NCARDS / NSUITS); i++)
		if (values[i] == value)
			for (j = 0; j < NSUITS; j++)
				if (suits[j] == suit)
					return (i*NSUITS + j);

	cout << "Warning: bad input value=" << value << ", suit=" << suit;
}

void Queue::war(qqq *a, qqq *b) {
	int steps = 0;
	int x, y;
	qqq c;
	bool inwar;
	inwar = false;
	init_queue(&c);
	const int MAXSTEPS = 10000;
	while ((empty(a)==1) && (!empty(b)==1)) {
		steps = steps + 1;
		x = dequeue(a);
		y = dequeue(b);
		enqueue(&c, x);
		enqueue(&c, y);
		if (inwar) {
			inwar = false;
		}
		else {
			if (value(x) > value(y) && steps<MAXSTEPS)
				clear_queue(&c, a);
			else if (value(x) < value(y))
				clear_queue(&c, b);
			else if (value(y) == value(x))
				inwar = true;
		}
	}

	if (empty(a) == 1 && empty(b) == 0)
		cout << "a wins in " << steps;
	else if (empty(a) == 0 && empty(b) == 1)
		cout << "b wins in " << steps;
	else if (empty(a) == 1 && empty(b) == 1)
		cout << "game tied after " << steps;
	else cout << "a and b tie in " << steps;
}
char Queue:: suit(int card) {
	return(suits[card%NSUITS]);
}
char Queue::value(int card) {
	return(values[card / NSUITS]);
}


int main()
{
	Queue *q = new Queue();
	qqq queue[2];
	char value, suit, c;
	int i;

	while (1) {
		for (i = 0; i < 1; i++) {
			q->init_queue(&queue[i]);

			while ((c = getchar()) != '\n') {
				if (c == EOF) return 1;
				if (c != ' ') {
					value = c;
					suit = getchar();
					q->enqueue(&queue[i], q->rank_card(value, suit));
				}
			}
		}
	
		q->war(&queue[0], &queue[1]);
	}
    return 0;
}

