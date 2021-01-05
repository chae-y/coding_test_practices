#include<iostream>

using namespace std;

int DT[101];

int f(int n) {
	if (n ==1)	return 1;
	if (!DT[n])	DT[n] = f(n - 1) + n;
	return DT[n];
}
int main() {
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}
