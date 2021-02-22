#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, start;
vector<int> v[1001];
int next_count[1001] = { 0, };
queue<int> q;
vector<int> result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int a;
		cin >> a;
		for (int j = 1; j < num; j++) {
			int b;
			cin >> b;
			v[a].push_back(b);
			next_count[b]++;
			a = b;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (next_count[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			cout << 0;
			break;
		}
		int now = q.front();
		q.pop();
		result.push_back(now);

		for (int j = 0; j < v[now].size(); j++) {
			int next = v[now][j];
			next_count[next]--;
			if (next_count[next] == 0) {
				q.push(next);
			}
		}

		if (result.size() == N) {
			for (int i = 0; i < N; i++) {
				cout << result[i] << "\n";
			}
		}
	}
	return 0;
}