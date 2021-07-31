#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string solution() {
	vector<string> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++) {
		string cur = v[i];
		string next = v[i + 1];
		if (next.substr(0, cur.size()) == cur) {
			return "NO";
		}
	}
	v.clear();
	return "YES";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout<<solution()<<endl;
	}
	return 0;
}