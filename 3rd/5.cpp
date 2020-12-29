#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int N, M, V;
vector<int> path[1001];
int check[1001] = { 0 };

int dfs(int v) {
	stack<int> s;
	s.push(v);
	cout << v << " ";
	check[v] = 1;
	while(!s.empty()){
		int current = s.top();
		s.pop();
		for (int i = 0; i < path[current].size(); i++) {
			int next = path[current][i];
			if (check[next] == 0) {
				cout << next << " ";
				check[next] = 1;
				s.push(current);
				s.push(next);
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
int bfs(int v) {
	queue<int> q;
	q.push(v);
	check[v] = 2;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << " ";
		for (int i = 0; i < path[current].size(); i++) {
			if (check[path[current][i]] != 2) {
				q.push(path[current][i]);
				check[path[current][i]] = 2;
			}
		}
	}
	cout << endl;
	return 0;
}

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start>> end;
		path[start].push_back(end);
		path[end].push_back(start);
	}
	for (int i = 1; i < N + 1; i++) {
		sort(path[i].begin(), path[i].end());
	}
	dfs(V);
	bfs(V);
	return 0;
}