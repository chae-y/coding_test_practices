#include<iostream>
#include<vector>

using namespace std;

int N;
vector<pair<int,int>> v[100001];
int result = 0, maxx = 0, max_v;
bool visited[100001];
int dis[100001];

int start(int x , int cost) {
	visited[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i].first]) {
			if (maxx < cost+ v[x][i].second) {
				maxx = cost+ v[x][i].second;
				max_v = v[x][i].first;
			}
			start(v[x][i].first,cost+ v[x][i].second);
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		while (true) {
			int temp,dim;
			cin >> temp;
			if (temp == -1)	break;
			cin >> dim;
			v[num].push_back({ temp,dim });
		}
	}
	start(1,0);
	result = maxx;
	maxx = 0;
	fill_n(visited, 100001, 0);
	start(max_v,0);
	result = max(maxx, result);
	cout << result;
	return 0;
}