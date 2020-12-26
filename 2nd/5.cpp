#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < 2*N; i++) {
		int temp;
		cin >> temp;
		sum += abs(temp);
	}
	cout << sum;
	return 0;
}