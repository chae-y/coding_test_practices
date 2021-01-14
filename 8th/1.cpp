#include<iostream>

using namespace std;

int L, R, C;
char space[30][30][30];
int f[30][30][30];
int minute, result, minm;

struct point {
	int i, j, k;
};

struct point startp;
struct point endp;

int start(int l, int r, int c) {
	minute++;
	cout << l << r << c << endl;
	if (space[l][r][c] == 'E') {
		result = minute;
	}
	f[l][r][c] = 1;
	//l++,l--,r++,r--,c++,c--
	bool A = l + 1 < L && space[l + 1][r][c] != '#' && f[l + 1][r][c] == 0;
	bool B = l - 1 >= 0 && space[l - 1][r][c] != '#' && f[l - 1][r][c] == 0;
	bool C = r + 1 < R && space[l][r + 1][c] != '#' && f[l][r + 1][c] == 0;
	bool D = r - 1 >= 0 && space[l][r - 1][c] != '#' && f[l][r - 1][c] == 0;
	bool E = c + 1 < C && space[l][r][c + 1] != '#' && f[l][r][c + 1] == 0;
	bool F = c - 1 >= 0 && space[l][r][c - 1] != '#' && f[l][r][c - 1] == 0;
	if (l + 1 < L && space[l + 1][r][c] != '#' && f[l + 1][r][c] == 0)	start(l + 1, r, c);
	if (l - 1 >= 0 && space[l - 1][r][c] != '#' && f[l - 1][r][c] == 0)	start(l - 1, r, c);
	if (r + 1 < R && space[l][r + 1][c] != '#' && f[l][r + 1][c] == 0)	start(l, r + 1, c);
	if (r - 1 >= 0 && space[l][r - 1][c] != '#' && f[l][r - 1][c] == 0)	start(l, r - 1, c);
	if (c + 1 < C && space[l][r][c + 1] != '#' && f[l][r][c + 1] == 0)	start(l, r, c + 1);
	if (c - 1 >= 0 && space[l][r][c - 1] != '#' && f[l][r][c - 1] == 0)	start(l, r, c - 1);
	if (!A && !B && !C && !D && !E && !F)	minute--;
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
					c = '.';
				}
				if (c == 'E') {
					//endp.i = i; endp.j = j; endp.k = k;
					//c = '.';
				}
				space[i][j][k] = c;
			}
		}
	}
	minute = -1;
	result = 0;
	minm = 0;
	fill_n(f[0][0], 2700, 0);
	//f[30][30][30] = { 0, };
	start(startp.i, startp.j, startp.k);
	if (result == 0)	cout << "Trapped!" << endl;
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