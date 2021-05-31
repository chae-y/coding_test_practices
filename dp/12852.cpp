#include<iostream>

using namespace std;

int dp[1000001];
int before[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	dp[1] = 0;
	before[1] = -1;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] =  dp[i / 2] + 1;
			before[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			before[i] = i / 3;
		}
	}

	cout << dp[N] << endl;

	while (N != -1) {
		cout << N << ' ';
		N = before[N];
	}
	return 0;
}