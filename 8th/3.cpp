#include<iostream>
#include<queue>;

using namespace std;

int N;
char map[100][100];
bool visited[100][100] = { 0, };
int maxx = -1000000000; int minn = 1000000000;

int solution(int x, int y, int z) {//x,y,°á°ú
	if (x == N - 1 && y == N - 1) {
		if (z > maxx)	maxx = z;
		if (z < minn)	minn = z;
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		int p = x + i;
		int q = y - i + 1;
		if (p >= N || q >= N)	continue;
		if (!visited[p][q]) {
			visited[p][q] = 1;
			if (map[x][y] == '+')	solution(p, q, z + (map[p][q] - '0'));
			else if (map[x][y] == '*')	solution(p, q, z * (map[p][q] - '0'));
			else if (map[x][y] == '-')	solution(p, q, z - (map[p][q] - '0'));
			else solution(p,q,z);
			visited[p][q] = 0;
		}
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	solution(0,0,map[0][0]-'0');
	cout << maxx << " " << minn;
	return 0;
}