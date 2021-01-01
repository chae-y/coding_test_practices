#include<iostream>

using namespace std;

int s[129][129];
int x, y;
int color = 1;

int two(int k) {
	int n=1;
	for (int i = 0; i < k; i++) {
		n *= 2;
	}
	return n;
}

int solution(int sx, int sy, int len, int a, int b) {
	if (len == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (s[sx + i][sy + j]==0) {
					s[sx + i][sy + j] = color;
				}
			}
		}
		color++;
	}
	else {
		int four = 0;
		if (sx <= a && (sx + (len / 2)) > a) {
			if (sy <= b && (sy + (len / 2)) > b) {
				four = 1;
				solution(sx, sy, len / 2, a, b);
				s[sx + len / 2][sy + len / 2 - 1] = color;
				s[sx + len / 2][sy + len / 2] = color;
				s[sx + len / 2 - 1][sy + len / 2] = color;
				color++;
			}
			else {
				four = 3;
				solution(sx, sy + len / 2, len / 2, a, b);
				s[sx + len / 2 - 1][sy + len / 2 - 1] = color;
				s[sx + len / 2][sy + len / 2] = color;
				s[sx + len / 2][sy + len / 2 - 1] = color;
				color++;
			}
		}
		else {
			if (sy <= b && (sy + (len / 2)) > b) {
				four = 2;
				solution(sx + len / 2, sy, len / 2, a, b);
				s[sx + len / 2 - 1][sy + len / 2 - 1] = color;
				s[sx + len / 2][sy + len / 2] = color;
				s[sx + len / 2 - 1][sy + len / 2] = color;
				color++;
			}
			else {
				four = 4;
				solution(sx + len / 2, sy + len / 2, len / 2, a, b);
				s[sx + len / 2][sy + len / 2 - 1] = color;
				s[sx + len / 2 - 1][sy + len / 2 - 1] = color;
				s[sx + len / 2 - 1][sy + len / 2] = color;
				color++;
			}
		}
		if (four != 1)	solution(sx, sy, len / 2, sx+(len / 2)-1, sy+(len / 2)-1);
		if (four != 2)	 solution(sx + len / 2, sy, len / 2, sx + len / 2, sy + (len / 2) - 1);
		if (four != 3)	solution(sx, sy + len / 2, len / 2, sx + (len / 2) - 1, sy + len / 2);
		if (four != 4)	solution(sx + len / 2, sy + len / 2, len / 2, sx + len / 2, sy + len / 2);
	}
	return 0;
}

int main() {
	int k;
	cin >> k >> x >> y;
	int n = two(k);
	s[x][y] = -1;
	solution(1, 1, n , x, y);
	for (int i = n; i > 0; i--) {
		for (int j = 1; j < n + 1; j++) {
			cout <<s[j][i] << " ";
		}
		cout << "\n";
	}
	return 0;
}