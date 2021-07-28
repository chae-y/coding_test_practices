#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int kor = (b - 1) / d + 1;
	int math = (c - 1) / e + 1;
	cout << a - max(kor, math);
	return 0;
}