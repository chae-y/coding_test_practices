#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int MAX;
int result;
vector<int> H;

int binary_search(int start, int end) {
	int mid = (start + end) / 2;
	int sum = 0;
	
	if (start > end)	return result;

	for (int i = 0; i < N; i++) {
		if (H[i] - mid < 0)	break;
		else sum += H[i] - mid;
	}

	if (sum >= M) {
		if (result < mid)	result = mid;
	}

	if (sum > M)	return binary_search(mid + 1, end);
	else return binary_search(start, mid - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		H.push_back(temp);
	}

	sort(H.begin(), H.end());
	reverse(H.begin(), H.end());
	MAX = H[0];

	cout<<binary_search(0, MAX);

	return 0;
}