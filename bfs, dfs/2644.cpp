#include<iostream>
#include<vector>

using namespace std;

int n, m, a, b;
vector<int> e[101];
int visited[101] = { 0, };
int result = 999999999;

int solution(int s, int c) {
	if (s == b) {
		result = min(result, c);
		return 0;
	}
	for (int i = 0; i < e[s].size(); i++) {
		if (visited[e[s][i]] == 0) {
			visited[e[s][i]] = 1;
			solution(e[s][i], c+1);
			visited[e[s][i]] = 0;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	visited[a] = 1;
	solution(a, 0);
	if (result == 999999999) cout << -1;
	else cout << result;

	return 0;
}