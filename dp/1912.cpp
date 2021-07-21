#include<iostream>

using namespace std;

int dp[100001], num[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int maxx = num[0];
	dp[0] = num[0];
	for (int i = 1; i <n; i++) {
		dp[i] = max(num[i], dp[i - 1] + num[i]);
		maxx = max(maxx, dp[i]);
	}
	cout << maxx;
	return 0;
}