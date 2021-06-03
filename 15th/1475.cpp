#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[9] = { 0, };
	
	int N;
	cin >> N;
	if (N == 0)	cout << 1;
	else {
		while (N > 0) {
			int temp = N % 10;
			if (temp == 9)	temp = 6;
			arr[temp]++;
			N /= 10;
		}
		int result = 0;
		arr[6] = (arr[6] + 1) / 2;
		for (int i = 0; i < 9; i++) {
			result = max(result, arr[i]);
		}
		cout << result;
	}
	return 0;
}