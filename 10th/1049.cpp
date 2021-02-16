#include<iostream>
#include<vector>

using namespace std;

int N, M;

int main() {
	cin >> N >> M;
	int six = N / 6 + 1;
	int six_min = 1000;
	int minn = 1000;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (six_min > a)	six_min = a;
		if (minn > b)	minn = b;
	}
	int re = N % 6;
	if (six_min < re * minn)	cout << six * six_min;
	else
	{
		if (six_min > minn * 6)	cout << minn*N;
		else cout << re * minn + six_min * (six - 1);
	}

	return 0;
}