#include<iostream>
#include<queue>

using namespace std;
int N;
int medicine[1500];
bool visited[1500][1500];

int solution(int n) {
	queue<pair<pair<int,int>,int>> q;
	fill_n(visited[0], 2250000, false);
	q.push({ { 0,0 } ,0});//left,right,È½¼ö
	visited[0][0] = true;
	int count;
	while (!q.empty()) {
		int l = q.front().first.first;
		int r = q.front().first.second;
		count = q.front().second;
		int time = count % 3;
		q.pop();
		if (l+r+1<=n && medicine[l] == time&&visited[l+1][r]==false) {
			visited[l + 1][r] = true;
			q.push({ {l + 1,r},count + 1 });
		}
		if (l + 1 + r <= n && medicine[n - r - 1] == time && visited[l][r+1] == false) {
			visited[l][r + 1]=true;
			q.push({ { l,r + 1 },count + 1 });
		}
	}

	return count;
}

int main() {
	cin >> N;
	for (int i = 0; i < 3 * N; i++) {
		char temp;
		cin >> temp;
		int tmp=0;
		if (temp == 'B')		tmp = 0;
		if (temp == 'L')		tmp = 1;
		if (temp == 'D')		tmp = 2;
		medicine[i] = tmp;
	}
	int result = solution(3*N);
	cout << result;
	return 0;
}