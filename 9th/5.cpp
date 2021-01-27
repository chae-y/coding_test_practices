#include<iostream>
#include<algorithm>

using namespace std;

int N;
int s[300];
int dp[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	dp[0] = s[0];
	dp[1] = s[0]+s[1];
	dp[2] = max(s[0], s[1]) + s[2];

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + s[i - 1]) + s[i];
	}

	cout << dp[N - 1];

	return 0;
}