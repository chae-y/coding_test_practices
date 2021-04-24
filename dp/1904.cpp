#include<iostream>

using namespace std;

int main() {
	int n;
	int dp[1000001] = { 0,1,2, };
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])% 15746;
	}
	cout << dp[n]% 15746;
	return 0;
}