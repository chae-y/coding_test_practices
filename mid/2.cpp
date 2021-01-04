#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct work{
	int s;
	int e;
	int w;
};
vector<work> v;

bool sorting(work w1, work w2) {
	if (w1.s == w2.s)	return w1.e < w2.e;
	return w1.s < w2.s;
}

bool solution(int t){
	int day = 1;
	int time = 1;
	sort(v.begin(), v.end(), sorting);
	for (int i = 0; i < t; i++) {
		if (day == v[i].s) {
			if (day > v[i].e)	return false;
			while (v[i].w > 0) {
				time++;
				v[i].w--;
				if (time == 9) {
					if (day > v[i].e)	return false;
					day++; time = 1;
					if (v[i].w != 0) { v[i].s++; sort(v.begin(), v.end(), sorting); }
				}
			}
			cout << endl;
		}
		else if (day>v[i].s)
		{
			v[i].s++;
		}
		else {
			day++; i--;
		}
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T;
		cin >> T;
		for (int j = 0; j < T; j++) {
			int s, e, w;
			cin >> s >> e >> w;
			work work;
			work.s = s; work.e = e; work.w = w;
			v.push_back(work);
		}
		if (solution(T))	cout << "yes"<<endl;
		else cout << "no"<<endl;
		v.clear();
	}
	return 0;
}