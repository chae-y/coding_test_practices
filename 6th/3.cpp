#include<iostream>
#include<vector>

using namespace std;

int N;
int G[1000][1000];

int solution(int n) {
	for (int i = 0; i<N ; i++) {
		while (G[n][i]) {
			G[n][i]--;
			G[i][n]--;
			solution(i);
		}
	}
	cout << n + 1 << " ";
	return 0;
}

int main() {
	cin >> N;
	bool Euler = true;
	for (int i = 0; i < N; i++) {
		int c = 0;
		for (int j = 0; j < N; j++) {
			cin >> G[i][j];
			c += G[i][j];
		}
		if (c % 2 == 1) {
			Euler = false;
			break;
		}
	}
	if (!Euler)	cout << "-1";
	else solution(0);
	return 0;
}