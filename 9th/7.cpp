#include<iostream>
#include<stdio.h>

using namespace std;

int N, M;
int map[100][100];
int visited[100][100] = { 0, };
int crash[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int dfs(int x, int y, int n_crash) {
	if (crash[x][y] > n_crash) crash[x][y] = n_crash;
	else return 0;

	if (x == N - 1 && y == M - 1)	return 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
		if (visited[nx][ny]) continue;

		visited[nx][ny] = 1;
		dfs(nx, ny, n_crash + map[nx][ny]);
		visited[nx][ny] = 0;
	}
	return 0;
}

int main() {

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	fill_n(crash[0], 10000, 99999999);
	visited[0][0] = 1;
	dfs(0, 0, 0);

	cout << crash[N - 1][M - 1];

	return 0;
}