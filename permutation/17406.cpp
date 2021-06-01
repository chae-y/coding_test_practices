#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, K;
int map[50][50];
int c_map[50][50];
int result = 300000;
vector<pair<pair<int, int>, int>> v;
vector<int> order;

void copy_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}

void change(int n) {
	if (n == K) {
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += c_map[i][j];
			}
			result = min(result, sum);
		}
	}
	else {
		int r = v[order[n]].first.first;
		int c = v[order[n]].first.second;
		int s = v[order[n]].second;
		for (int i = 0; i < s; i++) {
			int temp1 = c_map[r - s + i][c - s + i];
			int temp2 = c_map[r + s - i][c - s + i];
			for (int j = c - s + i; j < c + s - i; j++) {
				int tmp = temp1;
				temp1 = c_map[r - s + i][j+1];
				c_map[r - s + i][j + 1] = tmp;//상
				c_map[r + s - i][j] = c_map[r + s - i][j + 1];//하
			}
			for (int j = r - s + i; j < r + s - i; j++) {
				int tmp = temp1;
				temp1 = c_map[j + 1][c + s - i];
				c_map[j + 1][c + s - i] = tmp;
				//우
				if (j == r + s - i - 1)	c_map[j][c - s + i] = temp2;
				else{
					c_map[j][c - s + i] = c_map[j + 1][c - s + i];
				}//좌
			}
		}
		change(n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ {r-1,c-1},s });
		order.push_back(i);
	}

	do {
		copy_map();
		change(0);
	} while (next_permutation(order.begin(), order.end()));

	cout << result;
	return 0;
}