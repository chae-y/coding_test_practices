#include<iostream>

using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	int high = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
		high = max(b, high);
		last = max(a, last);
	}
	int cur = 0;
	int answer = 0;
	int i = 0;
	for (i; i <=last ; i++) {
		if (arr[i] == high) {
			break;
		}
		if (cur < arr[i]) {
			cur = arr[i];
		}
		answer += cur;
	}
	int j = last;
	cur = 0;
	for (j; j > i; j--) {
		if (arr[j] == high) {
			break;
		}
		if (cur < arr[j]) {
			cur = arr[j];
		}
		answer += cur;
	}
	answer += ((j - i + 1) * high);
	cout << answer;
	return 0;
}