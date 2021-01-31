#include<iostream>

using namespace std;

int N;
int map[2187][2187];
int result[3] = { 0,0,0 };//0,1,

int sol(int sx, int sy, int ex, int ey) {
	int all = true;
	for (int i = sx; i < ex; i++) {
		for (int j = sy; j < ey; j++) {
			if (map[sx][sy] != map[i][j]) {
				all = false;
				break;
			}
		}
	}
	int dis = ex - sx;
	if (all)	result[map[sx][sy]]++;
	else if (dis == 1)	return 0;
	else {
		sol(sx, sy, sx + dis / 3, sy + dis / 3);
		sol(sx + dis / 3, sy, sx + dis *2/ 3, sy + dis / 3);
		sol(sx + dis *2/ 3, sy, sx + dis * 3 / 3, sy + dis / 3);
		sol(sx, sy + dis / 3, sx + dis / 3, sy + dis*2 / 3);
		sol(sx + dis / 3, sy + dis / 3, sx + dis * 2 / 3, sy + dis *2/ 3);
		sol(sx + dis * 2 / 3, sy + dis / 3, sx + dis * 3 / 3, sy + dis *2/ 3);
		sol(sx, sy + dis *2/ 3, sx + dis / 3, ey);
		sol(sx + dis / 3, sy + dis *2/ 3, sx + dis * 2 / 3, ey);
		sol(sx + dis * 2 / 3, sy + dis *2/ 3, sx + dis * 3 / 3, ey);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == -1)	map[i][j] = 0;
			if (temp == 0)	map[i][j] = 1;
			if (temp == 1)	map[i][j] = 2;
		}
	}

	sol(0,0,N, N);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << " ";
	}

	return 0;
}