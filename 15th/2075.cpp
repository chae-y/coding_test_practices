#include<iostream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	set<int> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			s.insert(tmp);
			if (s.size() == N+1) {
				s.erase(*s.begin());
			}
		}
	}
	cout << *s.begin();
	return 0;
}