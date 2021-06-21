#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A,B,C;
	cin >> A>>B>>C;
	int arr[10] = { 0, };
	int mutiple = A * B * C;
	while (mutiple != 0) {
		arr[mutiple % 10]++;
		mutiple /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}