#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		sum += temp;
	}
	sort(v.begin(), v.end());
	bool second = false;
	int cnt = 1;
	int b_cnt = 0;
	int maxx = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i-1] == v[i])	cnt++;
		else {
			if (cnt > b_cnt) {
				b_cnt = cnt;
				maxx = v[i - 1];
				second = false;
			}
			else if (cnt == b_cnt && !second) {
				second = true;
				maxx = v[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > b_cnt) {
		maxx = v[n - 1];
	}
	else if (cnt == b_cnt && !second) {
		maxx = v[n - 1];
	}
	cout << round((double)sum / n) << endl;
	cout << v[n / 2] << endl;
	cout << maxx << endl;
	cout << v[n - 1] - v[0] << endl;
	return 0;
}