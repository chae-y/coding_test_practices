#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, L;
int map[100][100];
vector<pair<int, int>> v;
vector<pair<int, int>> v2;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void startGame() {
	int dir = 0; //0우 1하 2좌 3상
	int time = 0;
	int x = 0, y = 0;
	bool die = false;

	v2.push_back({ x,y });

	for (int i = 0; i < v.size(); i++) {
		while (time < v[i].first && !die) {
			x = x + dx[dir];
			y = y + dy[dir];
			if (x < 0 || x == N)  die = true;
			if (y < 0 || y == N)  die = true;
			auto it = std::find_if(v2.begin(), v2.end(), [&x, &y](const pair<int, int>& p) { return (p.first == x) && (p.second == y); });
			if (it != v2.end()) {
				die = true;
			}
			if (map[x][y] == 0) {
				v2.erase(v2.begin());
			}
			else {
				map[x][y] = 0;
			}
			v2.push_back({ x,y });
			time++;
			if (time == v[i].first) {
				dir += v[i].second;
				if (dir == -1)	dir = 3;
				if (dir == 4)	dir = 0;
			}
		}
	}
	while (!die) {
		x = x + dx[dir];
		y = y + dy[dir];
		if (x < 0 || x == N)  die = true;
		if (y < 0 || y == N)  die = true;
		auto it = std::find_if(v2.begin(), v2.end(), [&x, &y](const pair<int, int>& p) { return (p.first == x) && (p.second == y); });
		if (it != v2.end()) {
			die = true;
		}
		if (map[x][y] == 0) {
			v2.erase(v2.begin());
		}
		else {
			map[x][y] = 0;
		}
		v2.push_back({ x,y });
		time++;
	}
	cout << time;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a-1][b-1] = -1;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		if (dir == 'L') {
			v.push_back({ time,-1 });
		}
		else v.push_back({ time,1 });
	}

	sort(v.begin(), v.end());

	startGame();

	return 0;
}