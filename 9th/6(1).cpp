#include<iostream>

using namespace std;

int N,M;
int cost[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int mincost = 51;
	int mini;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		cost[i] = temp;
		if (temp <= mincost) {
			mincost = temp;
			mini = i;
		}
	}
	cin >> M;

	int len = M / mincost;
	int rest = M % mincost;

	int result[50];
	int zero = 0;

	for (int i = 0; i < len; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (cost[j] <= rest + mincost) {
				rest = rest - cost[j] + mincost;
				result[i] = j;
				break;
			}
		}
		if (result[zero] == 0) {
			zero++;
			rest += mincost;
		}
	}

	if (zero == len) cout << 0;
	else {
		for (int i = zero; i < len; i++) {
			cout << result[i];
		}
	}
	return 0;
}