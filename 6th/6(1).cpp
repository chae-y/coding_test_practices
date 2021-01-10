#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V, E, K;
//int G[20001][20001];


vector<pair<int,int>> edge[20001];
pair<int, bool> dis[20001];


int solution(int n) {
	for (int i = 0; i < edge[n].size(); i++) {
		//i는 n까지+w (단 , 합이 그 전꺼보다 작아야 업데이트)false인거는 무조건 커서 안해도돼
		if(dis[edge[n][i].first].second&&dis[edge[n][i].first].first>dis[n].first+edge[n][i].second)
			dis[edge[n][i].first].first = dis[n].first + edge[n][i].second;
	}
	//최소값으로 solution,true인거 중에서
	//sort(dis[1], dis[K], comp1);
	int min=0;
	for (int i = 2; i <= V; i++) {
		//cout << "d" << dis[i].first<<" "<<dis[i].second;
		if (dis[i].second && dis[i].first < dis[min].first)	min = i;
	}
	//cout << "min"<<min << endl;
	if (min) {
		dis[min].second = false;
		solution(min);
	}
	return 0;
}

int main() {
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
	}
	for (int i = 0; i <= V; i++) {
		dis[i].first = 123456789; dis[i].second = true;
		
	}
	dis[K].first = 0; dis[K].second = false;
	solution(K);
	for (int i=1; i <= V; i++) {
		if (dis[i].first == 123456789)	cout << "INF";
		else cout << dis[i].first << endl;
	}
	return 0;
}