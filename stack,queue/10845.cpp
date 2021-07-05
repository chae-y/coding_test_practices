#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	queue<int> q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		if (temp == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (temp == "pop") {
			if (q.empty())	cout << -1<<endl;
			else {
				cout << q.front()<<endl;
				q.pop();
			}
		}
		else if (temp == "size") {
			cout << q.size() << endl;
		}
		else if (temp == "empty") {
			cout << q.empty() << endl;
		}
		else if (temp == "front") {
			if (q.empty())	cout << -1 << endl;
			else {
				cout << q.front() << endl;
			}
		}
		else if (temp == "back") {
			if (q.empty())	cout << -1 << endl;
			else {
				cout << q.back() << endl;
			}
		}
		else {
			cout << "잘못된 입력" << endl;
		}
	}
	
	return 0;
}