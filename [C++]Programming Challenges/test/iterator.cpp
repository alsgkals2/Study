//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <list>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::const_reverse_iterator criter(v.rbegin());
//	for (; criter != v.rend(); criter++) {
//		cout << *criter << " ";
//	}cout << endl;
//
//	reverse_iterator<vector<int>::iterator> reverse_iter(v.begin());
//	reverse_iterator<vector<int>::iterator> reverse_itere(v.end());
//
//	for (; reverse_itere != reverse_iter; reverse_itere++) {
//		cout << *reverse_itere << " ";
//	}cout << endl;
//
//	vector<int>::iterator iter = v.begin() + 1;
//	vector<int>::const_iterator citer = iter; // const�� �Ϲ�����ȯ
//	vector<int>::reverse_iterator riter(iter);
//	reverse_iterator<vector<int>::const_iterator> rciter(iter);
//	cout << *iter << endl;
//	cout << *citer << endl;
//	cout << *riter << endl;
//	cout << *rciter << endl;
//	
//	vector<int> v2(10, 1);
//	//vector������ inserter
//	copy(v.begin(), v.end(), inserter<vector<int>>(v2,v2.end()));
//	//list������ inserter
//	list<int> lt(10, 1);
//	copy(v.begin(), v.end(), back_inserter<list<int>>(lt));
//	//copy(v.begin(), v.end(), front_inserter<list<int>>(lt));
//
//	//����� iterator
//
//	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
//	cout << endl;
//
//	lt.clear();
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	//transform+ostream_iterator+plus�� �̿��� ���
//	transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, " "), plus<int>());
//	cout << endl;
//
//	//�Է¹������� ���Ϳ� ����
//	copy(istream_iterator<int>(cin), istream_iterator<int>(), front_inserter<list<int>>(lt));
//
//
//	//�ݺ��ڸ� n��ŭ ��ġ�̵� (vector,dequeue�� �Լ��ʿ������ �������� ������)
//	//distance(a,b) = >a-b�� ����
//
//	iter = v.begin();
//	advance(iter, 3);
//	vector<int>::iterator iter2(v.begin());
//	int n = distance(iter,iter2); //-3
//	cout << n << endl;
//	n = iter - iter2;
//	cout << n << endl;//�����ƴ�
//	list<int>::iterator liter(lt.begin());
//	list<int>::iterator liter2(lt.begin());
//	advance(liter2, 2);
//	//n = liter2 - liter;//����
//	n = distance(liter, liter2);
//	//n = distance(liter2, liter);//����
//	cout << n << endl;
//	
//	copy(v.begin(), v.end(), ostream_iterator<int>(cout));
//
//	v.swap(vector<int>());
//	v2.swap(vector<int>());
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v2.push_back(1);
//	v2.push_back(1);
//	v2.push_back(1);
//	vector<int> v3(6);
//	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
//
//	return 0;
//}