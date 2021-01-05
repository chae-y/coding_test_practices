#include<iostream>

using namespace std;

int DT[100001];

int f(int n) {
	if (n <= 2)	return 1;
	if (!DT[n])	DT[n] = f(n - 1) + f(n - 2);
	return DT[n];
}
int main() {
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}