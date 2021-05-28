#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,H;
	cin >> N >>H;
	vector<int> v1;//석순
	vector<int> v2;//종유석
	for (int i = 0; i < N / 2; i++) {
		int a, b;//a석순b종유석
		cin >> a >> b;
		v1.push_back(a);
		v2.push_back(b);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(), v2.end());
	int cnt = 0;
	int mmin = N + 1;
	for (int i = 1; i <= H; i++) {
		int temp = v1.size()-(lower_bound(v1.begin(),v1.end(),i)-v1.begin());
		temp+= (v2.size() - (upper_bound(v2.begin(), v2.end(), H-i) - v2.begin()));
		if (mmin == temp)	cnt++;
		if (mmin > temp) {
			mmin = temp;
			cnt = 1;
		}
	}
	cout << mmin<<" " << cnt;
	return 0;
}