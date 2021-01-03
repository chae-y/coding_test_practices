#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int temp;
	stack<pair<int, int>> s;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		while (!s.empty() && s.top().second < temp)	s.pop();
		if (!s.size())	cout << "0 ";
		else cout << (s.top().first + 1) << " ";
		s.push(make_pair(i, temp));
	}

	return 0;
}