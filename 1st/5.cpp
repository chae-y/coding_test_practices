#include<iostream>
#include<queue>

using namespace std;

int main() {
	queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << "size: " << q.size() << endl;

	cout << q.front() << endl;//큐의 맨 위 반환
	q.pop();//큐 맨위 삭제

	cout << q.front() << endl;//큐의 맨 위 반환
	q.pop();//큐 맨위 삭제

	cout << q.front() << endl;//큐의 맨 위 반환
	q.pop();//큐 맨위 삭제

	cout << "empty? " << q.empty() << endl;

	return 0;
}