#include <iostream>
using namespace std;

int sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}//�̰ž��� stack �� ���� ������

int pluss(int i) {
	if (i == 0) return 1;
	else return i + pluss(i - 1);
}

int main() {
	int n;
	cin >> n;
	cout << pluss(n);
	//cout << sum(n);
}