#include<iostream>

using namespace std;

int f(int n, int k) {
	if (n < k) {
		cout << n;
		return 0;
	}
	f(n / k, k);
	cout << (n % k);
}

int main() {
	int n,k;
	cin >> n >> k;
	f(n, k);
	return 0;
}