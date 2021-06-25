#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<pair<int, int>> bus[1001];
int start, endd;
int result[1001];

int bfs(int s, int cost) {
	fill_n(result, 1001, 999999999);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (result[cur] < cost)	continue;

		for (int i = 0; i < bus[cur].size(); i++) {
			int n_cur = bus[cur][i].first;
			int n_cost = bus[cur][i].second+cost;

			if (result[n_cur] > n_cost) {
				result[n_cur] = n_cost;
				pq.push({ -n_cost,n_cur });//작은거부터 꺼내려고
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back({ b,c });
	}
	
	cin >> start >> endd;
	bfs(start, 0);
	cout << result[endd];
	return 0;
}