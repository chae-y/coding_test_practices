#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K;
	cin >> N>>K;
	int arr[5001] = { 0, };
	int cur = 0;
	cout << "<";
	for(int j=0; j<N-1; j++){
		for (int i = 0; i < K; i++ ) {
			if (++cur > N)	cur = 1;
			if (arr[cur]) i--;
		}
		arr[cur] = 1;
		cout << cur << ", ";
	}
	for (int i = 0; i < K; i++) {
		if (++cur > N)	cur = 1;
		if (arr[cur]) i--;
	}
	cout << cur << ">";
	return 0;
}