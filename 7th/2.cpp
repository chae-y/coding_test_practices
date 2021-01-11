#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> v;
int DP[501];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());

	DP[0] = 1;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second && tmp < DP[j])	tmp = DP[j];
		}
		DP[i] = tmp + 1;
	}
	sort(DP, DP + n);
	cout << n - DP[n-1];
	return 0;
}