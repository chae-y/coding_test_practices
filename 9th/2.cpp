#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int map[20][20];
int visited[20][20];
int s_size = 2;
int eat = 0;
vector<pair<pair<int, int>,int>> v;

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

int bfs(int x, int y) {
	int distance = 99999999;
	fill_n(visited[0], 400, 0);
	v.clear();
	queue<pair<int, int>> q;
	q.push({ x,y });
	
	while (!q.empty()) {
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = current_x + dx[i];
			int yy = current_y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N)	continue;
			if (visited[xx][yy] == 0 && s_size >= map[xx][yy]) {
				visited[xx][yy] = visited[current_x][current_y] + 1;
				if (map[xx][yy] > 0 && map[xx][yy] < s_size) {
					if (distance >= visited[xx][yy]) {
						distance = visited[xx][yy];
						v.push_back({ { distance,xx }, yy });
					}
				}
				q.push({ xx,yy });
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int x=-1, y=-1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 9) {
				x = i; y = j;
				map[i][j] = 0;
			}
		}
	}
	int result = 0;
	bfs(x, y);
	while (!v.empty()) {
		sort(v.begin(), v.end());
		eat++;
		result += v[0].first.first;
		x = v[0].first.second;
		y = v[0].second;
		map[x][y] = 0;
		if (s_size == eat) {
			s_size++;
			eat = 0;
		}
		bfs(x, y);
	}
	
	cout << result;

	return 0;
}