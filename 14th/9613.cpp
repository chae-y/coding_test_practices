#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

int GCD(int a, int b) {
	if (a % b == 0)	return b;
	return GCD(b,a%b);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		long long sum = 0;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum += GCD(v[j], v[k]);
			}
		}
		v.clear();
		cout << sum << endl;
	}
	return 0;
}