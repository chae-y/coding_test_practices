#include<iostream>

using namespace std;

int DT[101];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == 1)	DT[i] = 1;
		else
		{
			DT[i] = DT[i-1] + i;
		}
	}
	cout << DT[n];
	return 0;
}