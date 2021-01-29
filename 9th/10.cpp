#include<iostream>
#include<string>

using namespace std;

int n,m;
int num[10] = { 0, };

bool check(int current) {
	string current_st = to_string(current);
	for (int i = 0; i < current_st.length(); i++) {
		if (num[current_st[i] - '0'] == 1) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		num[temp] = 1;
	}

	string st = to_string(n);

	int result = abs(n - 100);
	
	for (int i = 0; i <=1000000; i++) {
		if (check(i)) {
			int temp = abs(n - i) + to_string(i).length();
			result = min(result, temp);
		}
	}
	cout << result;

	return 0;
}