//#include <iostream>
//
//#include "vector"
//#include <math.h>
//#include <string>
//#include <map>
//#include <queue>
//
//using namespace std;
//
//
//void Object(int i) {
//	cout << i << " ";
//
//}
//
//void for_each(int* begin, int* end, void(*Ob)(int)) {
//	while (begin != end) {
//		Ob(*begin++);
//	}
//}
//
//
//class Point {
//	int x, y;
//
//public:
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
//
//	void Print(int i) {
//		cout << i << " ";
//	}
//
//	const Point operator+(const Point& p) {
//		Point p3;
//		p3.x = p.x + x;
//		p3.y = p.y + y;
//		cout << "+ 오퍼레이터 작동" << endl;
//		return p3;
//	}
//
//	void operator()(int _x, int _y) {
//		cout << "()오퍼레이터 작동" << endl;
//		this->x = _x;
//		this->y = _y;
//	}
//	const Point& operator--() {
//		this->x--;
//		this->y--;
//		return *this;
//	}
//	const Point operator-- (int i) {
//		Point returnP;
//		returnP.x = x--;
//		returnP.y = y--;
//		return returnP;
//	} //후위
//
//	const Point operator[] (int idx) {
//		Point p;
//		p.x = x;
//		p.y = y;
//		return p;
//	} 
//	operator int(){
//		cout << "int 변환 함수 호출";
//		return x;
//	}
//};
//
//class SmartPointer {
//	Point* pt;
//public:
//	SmartPointer(Point* p) :pt(p) {}
//	SmartPointer() { delete pt; }
//
//	Point* operator->() const { return pt; }
//	Point& operator*() const { return *pt; }
//};
//
//
//int main(void) {
//	Point p1(1, 2), p2(2, 3);
//	Point p3;
//
//	p3 = p1 + p2;
//
//	p1(10, 10);
//	p2(20, 20);
//
//	p3 = --p1;
//	p3 = p2--;
//
//	void (*ob)(int);
//	ob = Object;
//
//	vector<Point> pVector;
//	pVector.push_back(p1);
//	pVector.push_back(p2);
//	pVector.push_back(p3);
//
//	Point p4;
//	p4 = pVector[2];
//
//	//SmartPointer sp = new Point();
//	
//	int trans = 0;
//	trans = p1;
//
//	cout << endl;
//
//	Point* p5 = new Point(1,1);
//
//	void (Point::*pp)(int);
//	pp = &Point::Print;
//	(p1.*pp)(10);
//	(p5->*pp)(10); 
//
//
//	cout << "foreach 호출"<<endl;
//	int arr[5] = { 1,2,3,4,5 };
//	for_each(arr, arr + 5, Object);
//
//	return 0;
//}
///*
//
//#include <string>
//
//class StockList
//{
//public:
//static string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
//{
//string resultS;
//
//
//for(int i=0; i<lstOfArt.size(); i++){
//for(int j=0; j<categories.size(); j++){
//if(lstOfArt[i][0] == categories[i][0]){
//&lstOfArt[i][lstOfArt[i].find(" ")+1]
//
//break;
//}
//}
//}
//
//}
//
//};
//
//*/