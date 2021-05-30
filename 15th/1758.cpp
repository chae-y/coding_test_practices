#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v;
	v.push_back(1000001);
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),compare);
	long long result = 0;
	for (int i = 1; i <= N; i++) {
		if (v[i] - (i - 1) <= 0)
			continue;
		result += v[i] - (i - 1);
	}
	cout << result;
	return 0;
}