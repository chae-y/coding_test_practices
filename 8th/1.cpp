#include<iostream>
#include<queue>

using namespace std;

int L, R, C;
char space[30][30][30];
int f[30][30][30];

struct point {
	int i, j, k;
};

struct point startp;
struct point endp;

int start(int l, int r, int c) {
	queue<pair<pair<int, int>, pair<int, int>>> q;//l,r,c,minute
	int visited[30][30][30] = { 0, };
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
	}
	if (space[l][r][c] == 'E') {
		return 0;
	}
	//char temp = space[l][r][c];
	//space[l][r][c] = '#';
	//l++,l--,r++,r--,c++,c--
	if (l + 1 < L && space[l + 1][r][c] != '#' && f[l + 1][r][c] == 0) {if(d[l + 1][r][c] > d[l][r][c]+1) d[l + 1][r][c] = d[l][r][c] + 1; start(l + 1, r, c); }
	if (l - 1 >= 0 && space[l - 1][r][c] != '#' && f[l - 1][r][c] == 0)	{if(d[l - 1][r][c] > d[l][r][c]+1)d[l - 1][r][c] = d[l][r][c] + 1; start(l - 1, r, c);}
	if (r + 1 < R && space[l][r + 1][c] != '#' && f[l][r + 1][c] == 0) {if(d[l][r + 1][c] > d[l][r][c]+1) d[l][r + 1][c] = d[l][r][c] + 1; start(l, r + 1, c); }
	if (r - 1 >= 0 && space[l][r - 1][c] != '#' && f[l][r - 1][c] == 0) {if(d[l][r - 1][c] > d[l][r][c] + 1) d[l][r - 1][c] = d[l][r][c] + 1; start(l, r - 1, c); }
	if (c + 1 < C && space[l][r][c + 1] != '#' && f[l][r][c + 1] == 0) {if(d[l][r][c + 1] > d[l][r][c] + 1) d[l][r][c + 1] = d[l][r][c] + 1; start(l, r, c + 1); }
	if (c - 1 >= 0 && space[l][r][c - 1] != '#' && f[l][r][c - 1] == 0) {if(d[l][r][c - 1] > d[l][r][c] + 1) d[l][r][c - 1] = d[l][r][c] + 1; start(l, r, c - 1); }
	//if (AA + BB + CC + DD + EE + FF >1)	minute--;
	//space[l][r][c] = temp;
	//cout << l << r << c << d[l][r][c]<< endl;
	return 0;
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
	start(startp.i, startp.j, startp.k);

	if (d[endp.i][endp.j][endp.k] == 99999999)	cout << "Trapped!" << endl;
	else
	{
		cout << "Escaped in " << d[endp.i][endp.j][endp.k] << " minute(s)." << endl;
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