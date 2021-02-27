#include<iostream>

using namespace std;

#define mod 1000000000

int N;
long long result = 0;
long long dp[101][10][1<<10];//자리수 숫자 visited
int full = (1 << 10) - 1;

int main() {
	cin >> N;
	for (int i = 1; i < 10; i++){
		dp[1][i][1 << i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= full; k++) {
				if(j==0)	dp[i][0][k|(1<<0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				if(j==9)	dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				if (j > 0 && j < 9) {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j+1][k]) % mod;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		result += dp[N][i][full];
	}
	cout << result%mod;
	return 0;
}