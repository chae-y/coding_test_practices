#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int DP[500][500];
int map[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, pair<int, int>>> v;

bool desc(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
	return x.first > y.first;
}

int sol(int x, int y, int c) {
	int maxx=c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 500)	continue;
		if (ny < 0 || ny >= 500)	continue;
		if (map[x][y] < map[nx][ny]) {
			if (DP[nx][ny] == -1) {//¾øÀ» ¶§
				maxx=max(maxx,sol(nx, ny, c + 1));
			}
			else {
				maxx=max(maxx,c + DP[nx][ny]);
			}
		}
	}
	return maxx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			v.push_back({ temp,{i,j} });
		}
	}

	sort(v.begin(), v.end(), desc);
	fill_n(DP[0], 250000, -1);

	int maxx = 0;
	for (int i = 0; i < v.size(); i++) {
		DP[v[i].second.first][v[i].second.second] = sol(v[i].second.first, v[i].second.second, 1);
		maxx = max(maxx, DP[v[i].second.first][v[i].second.second]);
	}
	cout << maxx;
	return 0;
}