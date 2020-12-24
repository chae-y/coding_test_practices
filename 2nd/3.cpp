#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, string>> v;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		v.push_back(make_pair(temp.length(), temp));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (i > 0 && v[i].second == v[i - 1].second) {
			continue;
		}
		cout << v[i].second<<endl;
	}

	return 0;
}