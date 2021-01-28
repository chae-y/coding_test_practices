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
		if (i != 0) {
			if (temp <= mincost) {
				mincost = temp;
				mini = i;
			}
		}
	}
	cin >> M;

	if (N == 1)	cout << 0;
	else {
		int zero = 0;
		if (mincost > cost[0]) {
			zero = mini;
			mini = 0;
			mincost = cost[0];
		}
		int len = M / mincost;
		int rest = M % mincost;

		if (rest < cost[zero] - mincost && mini == 0) {
			len = (M - cost[zero]) / mincost + 1;
		}

		int result[50];

		fill_n(result, len, mini);

		if (mini == 0 && cost[zero] <= M) {
			result[0] = zero;
			rest = (M - cost[zero]) % mincost;
		}
		if (mini == 0 && cost[zero] > M) cout << 0;
		else {
			for (int i = 0; i < len; i++) {
				if (rest == 0)	break;
				for (int j = N - 1; j >= 0; j--) {
					if (mini < j && rest >= cost[j] - cost[result[i]]) {
						rest = rest - cost[j] + cost[result[i]];
						result[i] = j;
						break;
					}
				}
			}

			for (int i = 0; i < len; i++) {
				cout << result[i];
			}
		}
	}
	return 0;
}