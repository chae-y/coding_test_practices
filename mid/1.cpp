#include<iostream>
#include<vector>

using namespace std;

bool num[988];

int solution(int q, int strike, int ball) {
	int hun, ten, one;
	hun = q / 100;
	ten = (q % 100) / 10;
	one = q % 10;
	for (int i = 123; i < 988; i++) {
		if (!num[i])	continue;
		int n_hun = i / 100;
		int n_ten = (i % 100) / 10;
		int n_one = i % 10;
		int n_st = 0;
		int n_b = 0;
		if (n_hun == n_ten || n_hun == n_one || n_one == n_ten)	num[i] = false;
		if (hun == n_hun)	n_st++;
		if (ten == n_ten)	n_st++;
		if (one == n_one)	n_st++;
		if (hun == n_ten || hun == n_one)	n_b++;
		if (ten == n_hun || ten == n_one)	n_b++;
		if (one == n_ten || one == n_hun)	n_b++;
		if (strike != n_st)	num[i] = false;
		if (ball != n_b)	num[i] = false;
	}
	return 0;
}

int main() {
	int N;
	cin >> N;
	fill_n(num, 988, true);
	for (int i = 0; i < 123; i++) {
		num[i] = false;
	}
	for (int i = 0; i < N; i++) {
		int q, ball, strike;
		cin >> q >> strike >> ball;
		solution(q, strike, ball);
	}
	int countt = 0;
	vector<int> v;
	for (int i = 120; i < 988; i++) {
		if (num[i]) { 
			countt++; 
			v.push_back(i);
		}
	}
	cout << countt << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}