#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> m;
	map<string, int> ::iterator it;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		m[temp]++;
	}
	int maxx = 0;
	string m_book;
	for (it = m.begin(); it != m.end(); it++) {
		if (maxx < it->second) {
			maxx = it->second;
			m_book = it->first;
		}
	}
	cout << m_book;
	return 0;
}