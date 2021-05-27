#include<iostream>
#include<vector>
#include<set>

using namespace std;

set<int> s;

bool check(int n) {
	while (n != 0) {
		if (n % 10 == 5 || n % 10 == 8)
			n /= 10;
		else return false;
	}
	return true;
}

void sol() {
	int a, b, c;
	cin >> a;
	vector<int> aa;
	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		aa.push_back(tmp);
	}
	cin >> b;
	vector<int> bb;
	for (int i = 0; i < b; i++) {
		int tmp;
		cin >> tmp;
		bb.push_back(tmp);
	}
	cin >> c;
	vector<int> cc;
	for (int i = 0; i < c; i++) {
		int tmp;
		cin >> tmp;
		cc.push_back(tmp);
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < c; k++) {
				int temp = aa[i] + bb[j] + cc[k];
				if(check(temp))
					s.insert(temp);
			}
		}
	}
	cout << s.size();
	aa.clear();
	bb.clear();
	cc.clear();
	s.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		sol();
	}
	return 0;
}