#include<iostream>
#include<vector>
using namespace std;

vector<int> v,lotto;

void dfs(int n, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = n; i < v.size(); i++) {
		lotto.push_back(v[i]);
		dfs(i + 1, depth + 1);
		lotto.erase(lotto.begin()+depth);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T != 0) {
		for (int i = 0; i < T; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		dfs(0, 0);
		cout << endl;
		v.clear();
		cin >> T;
	}

	
	return 0;
}