#include<iostream>

using namespace std;

int N, r, c, result=0;

int solution(int x, int y, int n) {
	if (x == r && y == c) {
		cout << result;
		return 0;
	}
	if (r < x + n && r >= x && c < y + n && c >= y) {
		solution(x, y, n / 2);
		solution(x, y + n / 2, n / 2);
		solution(x + n / 2, y, n / 2);
		solution(x + n / 2, y + n / 2, n / 2);
	}
	else result += n * n;
	return 0;
}

int main() {
	cin >> N >> r >> c;
	
	solution(0, 0, (1 << N));
	return 0;
}