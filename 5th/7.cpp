#include<iostream>

using namespace std;


int main() {
	int a,b;
	cin >> a>>b;
	int s[3];
	cin >> s[0] >> s[1] >> s[2];
	int *street = new int[b+1];
	fill_n(street, b + 1, 123456789);
	street[a] = 0;
	for (int i = a + 1; i <= b; i++) {
		int temp = 123456789;
		for (int k = 0; k < 3; k++) {
			if (i - s[k] >= a)
				temp = min(temp, street[i - s[k]] + 1);
		}
		street[i] = temp;
	}
	if (street[b] != 123456789)	cout << street[b] << endl;
	else cout << "-1" << endl;
	return 0;
}