#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> v;

int f(int n, int s, int m, int e) {
	if (n == 1) {
		v.push_back(make_pair(s, e));
	}
	else
	{
		f(n - 1, s, e, m);
		v.push_back(make_pair(s, e));
		f(n - 1, m, s, e);
	}
	return 0;
}

int main() {
	int n;
	cin >>n;
	f(n,1,2,3);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}