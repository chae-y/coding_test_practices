#include<iostream>

using namespace std;

int D[30][30];

int f(int n, int k) {
	if (n == k)	return 1;
	if (k == 1)	return n;
	if (!D[n][k]) {
		D[n][k] = f(n - 1, k - 1) + f(n - 1, k);
	}
	return D[n][k];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int N, M;
		cin >> N >> M;
		cout << f(M,N)<<endl;
	}
	return 0;
}