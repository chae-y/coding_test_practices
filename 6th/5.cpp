#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int parent[1001];

int find(int x) {
	if (x == parent[x])	return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[x] = y;
		return true;
	}
	return false;
}

struct edge {
	int u; int v; int w;
};

bool comp(edge e1, edge e2) {
	return e1.w < e2.w;
}

vector<edge> v;

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		edge e;
		cin >> e.u >> e.v >> e.w;
		v.push_back(e);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	int count = 0;
	for (int i = 0; i < M; i++) {
		if (merge(v[i].u, v[i].v)) {
			count += v[i].w;
		}
	}
	cout << count;
	return 0;
}
