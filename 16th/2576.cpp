#include<iostream>
#include<climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int sum = 0;
	int minn = 100;
	for (int i = 0; i < 7; i++) {
		int temp;
		cin >> temp;
		if (temp % 2 == 1) {
			sum += temp;
			minn = min(minn, temp);
		}
	}
	if (minn == 100) cout << -1;
	else {
		cout << sum << endl;
		cout << minn << endl;
	}
	return 0;
}