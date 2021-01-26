#include<iostream>
#include<vector>

using namespace std;

int N;
int maxx=0;
vector<pair<int, int>> v;

int bfs(int day, int sum) {
	if (day > N)	return 0;

	if (maxx < sum)	maxx = sum;

	for (int i = day; i < N; i++) {
		bfs(i+v[i].first, sum+v[i].second);
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int time, pay;
		cin >> time >> pay;
		v.push_back({time, pay});
	}

	for (int i = 0; i < N; i++) {
		bfs(i+v[i].first, v[i].second);
	}

	cout << maxx;

	return 0;
}