#include<iostream>
#include<queue>

using namespace std;

int L, R, C;
char space[30][30][30];
int visited[30][30][30] = { 0, };

struct point {
	int i, j, k;
};

struct point startp;

int start(int l, int r, int c) {
	queue<pair<pair<int, int>, pair<int, int>>> q;//l,r,c,minute
	fill_n(visited[0][0], 2700, 0);
	q.push({ { l,r }, { c,1 } });
	visited[l][r][c] = 1;
	//cout << l << r << c<<d[l][r][c] << endl;
	while (!q.empty()) {
		int z = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second.first;
		int minute = q.front().second.second;
		q.pop();

		if (space[z][y][x] == 'E')	return minute;

		if (z + 1 < L && space[z + 1][y][x] != '#' && visited[z + 1][y][x] == 0) {
			visited[z + 1][y][x] == 1; q.push({ {z + 1,y},{x,minute + 1} });
		}
		if (z - 1 >= 0 && space[z - 1][y][x] != '#' && visited[z - 1][y][x] == 0) {
			visited[z - 1][y][x] == 1; q.push({ {z - 1,y},{x,minute + 1} });
		}
		if (y + 1 < R && space[z][y + 1][x] != '#' && visited[z][y + 1][x] == 0) {
			visited[z][y + 1][x] == 1; q.push({ {z,y + 1},{x,minute + 1} });
		}
		if (y - 1 >= 0 && space[z][y - 1][x] != '#' && visited[z][y - 1][x] == 0) {
			visited[z][y - 1][x] == 1; q.push({ {z,y - 1},{x,minute + 1} });
		}
		if (x + 1 < C && space[z][y][x + 1] != '#' && visited[z][y][x + 1] == 0) {
			visited[z][y][x + 1] == 1; q.push({ {z,y},{x + 1,minute + 1} });
		}
		if (x - 1 >= 0 && space[z][y][x - 1] != '#' && visited[z][y][x - 1] == 0) {
			visited[z][y][x - 1] == 1; q.push({ {z,y},{x - 1,minute + 1} });
		}

	}
	return -1;
}


int escape(int l, int r, int c) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				char c;
				cin >> c;
				if (c == 'S') {
					startp.i = i; startp.j = j; startp.k = k;
				}
				/*if (c == 'E') {
					endp.i = i; endp.j = j; endp.k = k;
				}*/
				space[i][j][k] = c;
			}
		}
	}
	int result = start(startp.i, startp.j, startp.k);

	if (result == -1)	cout << "Trapped!" << endl;
	else
	{
		cout << "Escaped in " << result << " minute(s)." << endl;
	}
	return 0;
}

int main() {
	cin >> L >> R >> C;
	while (L != 0 && R != 0 && C != 0) {
		escape(L, R, C);
		cin >> L >> R >> C;
	}
	return 0;
}