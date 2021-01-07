#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> graph[101];

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (graph[i][j].first <= 0) continue;
			cout << i << " " << graph[i][j].first << " " << graph[i][j].second << " " << endl;
		}
	}
	return 0;
}