#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> v[50];
int visited[50];

int friends(int i) {
	int result = 0;
	fill_n(visited, 50, 0);
	visited[i] = 1;
	for (int j = 0; j < v[i].size(); j++) {
		if (!visited[v[i][j]]) result++;
		visited[v[i][j]] = 1;
		for (int k = 0; k < v[v[i][j]].size(); k++) {
			if (!visited[v[v[i][j]][k]]) { result++; visited[v[v[i][j]][k]] = 1; }
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == 'Y')	v[i].push_back(j);
		}
	}

	int maxx=0;
	for (int i = 0; i < N; i++) {
		int n = friends(i);
		maxx = max(maxx, n);
	}
	cout << maxx;
	return 0;
}