#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int N, M, X;
vector<pair<int, int>> edge[1001];
vector<int> distance(N + 1, INF);

vector<int> Dajkstra(int start) {
	vector<int> distance(N + 1, INF);
	distance[start] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (distance[current] < cost)	continue;

		for (int i = 0; i < edge[current].size(); i++) {
			if (distance[edge[current][i].first] > cost + edge[current][i].second) {
				distance[edge[current][i].first] = cost + edge[current][i].second;
				pq.push({ cost + edge[current][i].second ,edge[current][i].first });
			}
		}
	}

	return distance;
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, x;
		cin >> u >> v >> x;
		edge[u].push_back(make_pair(v, x));
	}
	int *go = new int[N+1];
	for (int i = 1; i <= N; i++) {
		vector<int> temp = Dajkstra(i);
		go[i] = temp[X];
	}
	vector<int> back = Dajkstra(X);
	vector<int> result;
	for (int i = 1; i <= N; i++) {
		result.push_back(go[i] + back[i]);
	}
	sort(result.begin(), result.end());
	cout << result[N-1];
	return 0;
}