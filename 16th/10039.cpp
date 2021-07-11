#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int summ = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		if (temp < 40)	temp = 40;
		summ += temp;
	}
	cout << summ / 5;
	return 0;
}