#include<iostream>

using namespace std;

int square[128][128];
int black=0, white=0;

bool two(int n) {
	if (n & (n - 1))	return false;
	else	return true;
}

int solution(int x, int y, int len) {
	bool all = true;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (square[i][j] != square[x][y]) {
				all = false;
				break;
			}
		}
		if (!all)	break;
	}
	if (all) {
		if (square[x][y] == 1)	black++;
		else white++;
	}
	else {
		solution(x, y, len / 2);
		solution(x, y+(len / 2), len / 2);
		solution(x+(len / 2), y, len / 2);
		solution(x+(len / 2), y+(len / 2), len / 2);
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	if (two(n)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp;
				cin >> temp;
				square[i][j] = temp;
			}
		}
		solution(0, 0, n);
	}
	else {
		cout << "2ÀÇ k½ÂÀÌ ¾Æ´Õ´Ï´Ù.";
	}
	cout << white << "\n" << black;
	return 0;
}