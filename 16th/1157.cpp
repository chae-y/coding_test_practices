#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	int alphabet[26] = { 0, };
	for (int i = 0; i < str.size(); i++) {
		alphabet[toupper(str[i]) - 'A']++;
	}
	int cnt = 0;
	int maxx = -1;
	char c;
	for (int i = 0; i < 26; i++) {
		if (maxx < alphabet[i]) {
			cnt = 1;
			c = 'A' + i;
			maxx = alphabet[i];
		}
		else if (maxx == alphabet[i])	cnt++;
	}

	if (cnt > 1)	cout << '?';
	else cout << c;
	return 0;
}