#include<iostream>

using namespace std;

int G[101][101];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (G[i][j] > 0)	cout << i << " " << j << " " << G[i][j] << endl;
		}
	}
	return 0;
}