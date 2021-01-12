#include<iostream>

using namespace std;

int solution(string s) {
	int left=0, right=s.length()-1;
	int add = 0;
	while (left < right) {
		if (s[left] == s[right]) {
			left++; right--;
		}
		else {
			add++; left++;
		}
	}
	cout << add;
	return 0;
}

int main() {
	string s;
	cin >> s;
	solution(s);
	return 0;
}