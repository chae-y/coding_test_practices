#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100001];

struct edge {
	int u, v, w;
};

bool comp(edge e1, edge e2) {
	return e1.w < e2.w;
}

int static find(int x) {
	if (x == parent[x])	return x;
	else return parent[x] = find(parent[x]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		parent[v] = u;
		return true;
	}
	return false;
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<edge> v;
	for (int i = 0; i < E; i++) {
		edge e;
		cin >> e.u >> e.v >> e.w;
		v.push_back(e);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	int len = 0;
	for (int i = 0; i < E; i++) {
		if (merge(v[i].u, v[i].v)) { 
			len += v[i].w;
		}
	}
	cout << len;
	return 0;
}