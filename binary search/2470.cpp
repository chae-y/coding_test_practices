#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,zero=0;
vector<int> al, san;
long long result = 99999999999999;
int a, b;

int sol(int x, int start, int end) {//y에서 이분분할
	int mid = (start + end) / 2;
	if (start>end) return 0;

	long long plus = al[mid] + san[x];

	if (abs(plus) < result) {
		result = abs(plus);
		a = san[x]; b = al[mid];
	}
	if (plus < 0) sol(x, mid + 1, end);
	else sol(x, start, mid - 1);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp == 0)	zero = 1;
		else if (temp > 0)	san.push_back(temp);
		else al.push_back(temp);
	}

	sort(san.begin(), san.end());
	sort(al.begin(), al.end());
	
	for (int i = 0; i < san.size(); i++) {
		sol(i, 0, al.size() - 1);
	}
	if (zero == 1) {
		if (result < san[0] && result < -al[al.size() - 1])	cout << b << " " << a;
		if (san[0] < result && san[0] < -al[al.size() - 1]) cout << 0 << " " << san[0];
		if (-al[al.size() - 1] < result && -al[al.size() - 1] < san[0])	cout << al[al.size() - 1] << 0;
	}
	else {
		long long alcal= 99999999999999,sans= 99999999999999;
		if (al.size() > 1)
			alcal = abs(al[al.size()-1] + al[al.size()-2]);
		if (san.size() > 1)
			sans = san[0] + san[1];
		if(min(min(alcal,sans),result)==alcal)	cout << al[al.size() - 2] << " " << al[al.size() - 1];
		if (min(min(alcal, sans), result)==sans)	cout << san[0] << " " << san[1];
		if (min(min(alcal, sans), result)==result)	cout << b << " " << a;
	}

	return 0;
}