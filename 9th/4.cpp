#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, zero;
int map[8][8];
int visited[8][8];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int result = 99999999;
list<int> l;
list<int>::iterator iter;
vector<pair<int, int>> clean;
vector<pair<int, int>> virus;

int bfs() {
	for (iter = l.begin(); iter != l.end(); iter++) {
		map[clean[*iter].first][clean[*iter].second] = 1;
	}

	int cnt = 0;
	fill_n(visited[0], 64, 0);
	
	for (int i = 0; i < virus.size(); i++) {
		queue<pair<int, int>> q;
		int x = virus[i].first;
		int y = virus[i].second;
		q.push({ x,y });

		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
				if (!visited[nx][ny] && map[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
					cnt++;
				}
			}
		}
	}

	if (result > cnt)	result = cnt;

	for (iter = l.begin(); iter != l.end(); iter++) {
		map[clean[*iter].first][clean[*iter].second] = 0;
	}
	return 0;
}

int wall(int idx) {
	if (l.size() == 3) {
		bfs();
		return 0;
	}
	for (int i = idx; i < zero; i++) {
		if (find(l.begin(), l.end(), i) != l.end()) continue;
		l.push_back(i);
		wall(idx);
		l.remove(i);
	}

	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 0)	clean.push_back({ i,j });
			if (temp == 2)	virus.push_back({ i,j });
		}
	}
	zero = clean.size();

	wall(0);

	cout << zero - result - 3;

	return 0;
}