#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		cout << N << " * " << i << " = " << N * i << endl;
	}
	return 0;
}