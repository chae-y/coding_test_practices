#include<iostream>

using namespace std;

int step(int n) {
	if (n == 1) return 1;
	if (n == 2)	return 2;
	return step(n-1)+step(n-2);
}

int main() {
	int n;
	cin >> n;
	cout<<step(n);
	return 0;
}