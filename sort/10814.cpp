#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector < pair<int, string>> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; string b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	stable_sort(v.begin(), v.end(),comp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}