#include<iostream>
#include<vector>
using namespace std;

int n;
long long DP[100][1000];
vector <int> v;

long long dp(int idx, int sum) {
	if (sum < 0 || sum>20)	return 0;
	if (idx == n - 2) {
		if (sum == v[n - 1]) DP[idx][sum] = 1;
		else DP[idx][sum] = 0;
		return DP[idx][sum];
	}
	if (DP[idx][sum] != -1)	return DP[idx][sum];

	long long check = 0;

	check += dp(idx + 1, sum + v[idx + 1]);
	check += dp(idx + 1, sum - v[idx + 1]);

	return DP[idx][sum] = check;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	fill_n(DP[0], 100000, -1);
	cout<<dp(0, v[0]);
	
	return 0;
}