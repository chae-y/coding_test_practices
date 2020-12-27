#include<iostream>

using namespace std;

int main() {
	int max=0;
	int index = 0;
	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		if (max < temp) {
			max = temp;
			index = i;
		}
	}
	cout << max << endl << index + 1 <<endl;
	return 0;
}