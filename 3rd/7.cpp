#include<iostream>

using namespace std;

int N;
int countt = 0;
int col[15];

bool ok(int i) {
	//1 가로 2 세로 3 대각선
	for (int j = i-1; j >= 0;j--) {
		if (col[j] == col[i])	return false;
		if ((i-j) == abs(col[i] - col[j]))	return false;
	}
	return true;
}

int queen(int i) {
	if (i == N)		countt++;
	else {
		for (int j = 0; j < N; j++) {
			col[i] = j;
			if (ok(i))	queen(i + 1);
		}
	}
	return 0;
}

int main() {
	cin >> N;
	queen(0);
	cout << countt;
	return 0;
}