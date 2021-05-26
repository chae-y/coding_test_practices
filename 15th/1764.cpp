#include<iostream>
#include<set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		s.insert(temp);
	}

	set<string> s2;

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		if (s.find(tmp) != s.end()) {
			s2.insert(tmp);
		}
	}
	cout << s2.size() << endl;
	for (string s: s2) {
		cout << s << endl;
	}
	return 0;
}