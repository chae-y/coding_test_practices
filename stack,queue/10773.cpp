#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	stack<int> stk;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			stk.pop();
		}
		else
		{
			stk.push(a);
		}
	}
	int sum = 0;
	while(!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}
	cout << sum;
	return 0;
}