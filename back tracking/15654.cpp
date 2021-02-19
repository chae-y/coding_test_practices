#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> v;
int arr[8];
bool visited[8] = { 0, };

int solution(int m) {
	if (m == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[m] = v[i];
			solution(m + 1);
			visited[i] = false;
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	solution(0);
	return 0;
}