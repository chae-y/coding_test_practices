#include<iostream>

using namespace std;

int D[101][101];

int f(int n, int k) {
	if (n == k)	return 1;
	if (k == 1)	return n;
	if (!D[n][k]) {
		D[n][k] = f(n - 1, k - 1) + f(n - 1, k);
	}
	return D[n][k];
}

int main() {
	int n,k;
	cin >> n>>k;
	cout << f(n, k);
	return 0;
}