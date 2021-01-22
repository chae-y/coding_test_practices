#include<iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int sum[1001];
	int total = 0;
	int index = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < i; j++) {
			total += i;
			sum[++index] = total;
			if (index == b) break;
		}
		if (index == b) break;
	}
	cout << sum[b] - sum[a - 1];

}