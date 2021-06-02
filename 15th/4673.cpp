#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10001] = { 1, };
	for (int i = 0; i < 9973; i++) {
		if (i < 10) {
			arr[i + i] = 1;
		}
		else if (i < 100) {
			arr[i + i / 10 + i % 10] = 1;
		}
		else if(i<1000){
			arr[i + i / 100 + i % 100 / 10 + i % 10] = 1;
		}
		else {
			arr[i + i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10] = 1;
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (!arr[i])	cout << i << endl;
	}
	return 0;
}