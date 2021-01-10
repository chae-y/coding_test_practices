#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;

int V, E, K;

vector<pair<int,int>> edge[20001];

vector<int> solution() {
	vector<int> distance(V + 1, INF);
	distance[K] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,K });

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
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
	}
	vector<int> result = solution();
	for (int i=1; i <= V; i++) {
		if (result[i] == INF)	cout << "INF"<<"\n";
		else cout << result[i] << "\n";
	}
	return 0;
}