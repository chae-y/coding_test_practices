#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	int now = 1;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == now)	now = b;
		else if (b == now)	now = a;
	}
	cout << now;
	return 0;
}