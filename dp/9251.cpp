#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	int arr[1001][1001] = { 0, };
	for (int i = 1; i < s1.size(); i++) {
		for (int j=1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	cout << arr[s1.size()-1][s2.size()-1];
	return 0;
}