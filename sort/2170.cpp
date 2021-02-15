#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<long long, long long>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long current, result;
	long long s,e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());
	current = v[0].second;
	result = v[0].second - v[0].first;
	for (int i = 1; i < n; i++) {
		s = v[i].first;
		e = v[i].second;
		if (current >= s) {
			if (e >= current) {
				result += e - current;
				current = e;
			}
		}
		else {
			current = e;
			result += e - s;
		}
	}

	cout << result;
	return 0;
}