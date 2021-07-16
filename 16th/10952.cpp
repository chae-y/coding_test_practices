#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		cout << a+b << endl;
		cin >> a >> b;
	}

	return 0;
}