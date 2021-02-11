#include<iostream>

using namespace std;

int deque[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int front = 0; int back = 0;
	int n;
	cin >> n;
	int f = 0;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		
		if (temp == "push_front") {
			int x;
			cin >> x;
			if (front == 0)	front = 10000;
			front--;
			deque[front] = x;
			f = 1;
		}
		if (temp == "push_back") {
			int x;
			cin >> x;
			deque[back] = x;
			back++;
			if (back == 10000) back = 0;
			f = 1;
		}
		if (temp == "pop_front") {
			if (back == front &&f==0)	cout << "-1\n";
			else {
				cout << deque[front] << "\n";
				front++;
				if (front == 10000)	front = 0;
			}
			f = 0;
		}
		if (temp == "pop_back") {
			if (back == front&&f == 0)	cout << "-1\n";
			else {
				if (back == 0)	back = 10000;
				back--;
				cout << deque[back] << "\n";
			}
			f = 0;
		}
		if (temp == "size") {
			if (back == front) {
				if (f == 0) cout << "0\n";
				else cout << "10000\n";
			}
			else if (back > front )	cout << back - front << "\n";
			else cout << 10000 - front + back << "\n";
		}
		if (temp == "empty") {
			if (back == front&&f==0)	cout << "1\n";
			else cout << "0\n";
		}
		if (temp == "front") {
			if (back == front && f == 0)	cout << "-1\n";
			else cout << deque[front]<<"\n";
		}
		if (temp == "back") {
			if (back == front && f == 0)	cout << "-1\n";
			else if (back == 0)	cout << deque[9999]<<"\n";
			else cout << deque[back-1] << "\n";
		}
	}

	return 0;
}