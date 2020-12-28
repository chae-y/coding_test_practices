#include<iostream>

using namespace std;

int arr[10001];

int solution(int start, int end, int k) {
	int m;
	while (end > start) {
		m = (end+start) / 2;
		if (arr[m] < k)	start = m + 1;
		else end = m;
	}
	return end+1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	int k;
	cin >> k;
	cout<<solution(0, n ,k)<<endl;

	return 0;
}