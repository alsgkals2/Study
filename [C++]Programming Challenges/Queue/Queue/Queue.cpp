// Queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>
#include <string.h>
using namespace std;

class Queue {
public:
	int sss;
	int* queue;
	int first;
	int last;
	int count;
	Queue(int);
	~Queue();

	void enqueue(int);
	int dequeue();
	int size();
	int empty();
	int front();
	int back();
};

void Queue::enqueue(int x)// 정수 X를 큐에 넣는 연산이다.
{
	if (count + 1 < sss) {//명령어수만큼 배열선언했기 때문에 항상 성립함.
		queue[last] = x;
		last = (last + 1) % sss;
		count++;
	}
}

int Queue::dequeue() {
	int save = 0;
	if (count - 1 >= 0) {
		save = first;
		first = (first + 1) % sss;
		count--;
		return queue[save];
	}

	else return -1; //뺄 숫자가 없는경우
}

int Queue::size() {
	return count;
}

int Queue::empty() {
	if (count == 0) return 1;
	else return 0;
}

int Queue::front() {
	if (count == 0) return -1;
	else {
		return queue[first];
	}
}
int Queue::back() {
	if (count == 0) return -1;
	else {
		return queue[last - 1];
	}
}
Queue::Queue(int s) {
	queue = new int[s];
	first = 0;
	last = 0;
	count = 0;
	sss = s;
}
Queue::~Queue() {
	delete[] queue;
}
int main()
{
	int s;
	cin >> s;
	Queue * q = new Queue(s);

	char* input;

	for (int i = 0; i < s; i++) {
		input = new char[6];
		cin >> input;
		if (!strcmp(input, "push")) {
			delete[] input;
			int x = 0;
			cin >> x;
			q->enqueue(x);
			continue;
		}
		else if (!strcmp(input, "pop")) {
			delete[] input;
			cout << q->dequeue() << endl;
			continue;
		}
		else if (!strcmp(input, "size")) {
			delete[] input;
			cout << q->size() << endl;
			continue;
		}
		else if (!strcmp(input, "empty")) {
			delete[] input;
			cout << q->empty() << endl;
			continue;
		}
		else if (!strcmp(input, "front")) {
			delete[] input;
			cout << q->front() << endl;
			continue;
		}
		else if (!strcmp(input, "back")) {
			delete[] input;
			cout << q->back() << endl;
			continue;
		}
	}
	delete q;
	return 0;
}