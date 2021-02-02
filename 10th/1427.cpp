#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string temp;
	cin >> temp;
	int *a = new int[temp.size()];
	for (int i = 0; i < temp.size(); i++) {
		a[i] = temp[i]-'0';
	}
	sort(a, a+temp.size());
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout << a[i];
	}
}