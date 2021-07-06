#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> p[2000];
bool visited[2000];

bool result = false;

int dfs(int depth, int cur) {
	visited[cur] = true;
	if (depth == 4) {
		result = true;
		return 0;
	}

	for (int i = 0; i < p[cur].size(); i++) {
		if (result) return 0;
		if (!visited[p[cur][i]])	dfs(depth + 1, p[cur][i]);
	}
	visited[cur] = false;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;
	cin >> N>>M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < p[cur].size(); i++) {
			int next = p[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	for(int i = 0; i < N; i++) {
		fill_n(visited, 2000, 0);
		dfs(0, i);
	}
	cout << result;
	return 0;
}