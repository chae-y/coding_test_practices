#include<iostream>

using namespace std;

int N;
long long result = 0;
long long a[101][10];//자리수 숫자

long long sol(int x, int y) {
	if (x == 0)	a[x][y] = 0;
	if (x == 1)	a[x][y] = 1;
	if (x == 2) {
		if (y == 0 || y == 9)	a[x][y] = 1;
		else a[x][y] = 2;
	}
	if (x > 2 && y == 0)	a[x][y] = sol(x - 1, 1);
	if (x > 2 && y == 9)	a[x][y] = sol(x - 1, 8);
	if (x > 2 && y != 0 && y != 9)	a[x][y] = (a[x-1][y-1]? a[x - 1][y - 1]:sol(x - 1, y - 1)) + (a[x - 1][y + 1]? a[x - 1][y +1]:sol(x - 1, y + 1));
	return a[x][y];
}
int main() {
	cin >> N;
	for (int i = 1; i < 10; i++) {
		result += sol(N, i) % 1000000000;
	}
	cout << result%1000000000;
	return 0;
}