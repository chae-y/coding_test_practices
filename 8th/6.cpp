#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> v[100000];
int visited[100000];
int cnt;
vector<pair<int, int>> result;

int dfs(int start) {
	cnt++;
	visited[start] = 1;
	for (int i = 0; i < v[start].size(); i++) {
		int temp = v[start][i];
		if (!visited[temp]) {
			dfs(temp);
		}
	}
	return 0;
}
int compare(pair<int, int> v1, pair<int, int> v2) {
	if (v1.first == v2.first)	return v1.second < v2.second;
	return v1.first > v2.first;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		fill_n(visited, 100000, 0);
		cnt = 0;
		dfs(i);
		result.push_back(make_pair( cnt,i ));
	}
	sort(result.begin(), result.end(),compare);
	int maxx=result[0].first;
	for (int i = 0; i <result.size(); i++) {
		if (result[i].first == maxx)
			cout << result[i].second << " ";
		else
		{
			break;
		}
	}
	return 0;
}