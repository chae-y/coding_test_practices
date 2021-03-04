#include<iostream>
#include<algorithm>

using namespace std;

int A[50];
int B[50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n);
	int s=0;
	for (int i = 0; i < n; i++) {
		s += A[i] * B[n - i-1];
	}
	cout << s;
	return 0;
}