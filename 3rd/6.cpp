#include<iostream>

using namespace std;

int map[5][5] = {
	1,1,1,1,1,
	1,0,1,0,0,
	1,0,1,1,1,
	1,0,0,1,0,
	1,1,1,1,1
};
int n = 0;

int dfs(int x, int y) {
	if (x == 4 && y == 4) n++;
	else {
		map[x][y] = 0;
		if (x < 4 && map[x + 1][y] == 1)	dfs(x + 1, y);
		if (x > 0 && map[x - 1][y] == 1)	dfs(x - 1, y);
		if (y < 4 && map[x][y + 1] == 1)	dfs(x, y + 1);
		if (y > 0 && map[x][y - 1] == 1)	dfs(x, y - 1);
		map[x][y] = 1;
	}
	return 0;
}

int main() {
	//4,4 도착하면 n증가
	dfs(0, 0);
	cout << n;
	return 0;
}