#include<iostream>
#include<algorithm>
#include<tuple>

using namespace std;

int N;

struct person {
	string name;
	int day;
	int month;
	int year;
};

person p[100];

bool comp(person p1, person p2) {
	return make_tuple(p1.year, p1.month, p1.day) > make_tuple(p2.year, p2.month, p2.day);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].name >> p[i].day >> p[i].month >> p[i].year;
	}
	sort(p, p+N, comp);

	cout << p[0].name << "\n" << p[N - 1].name;
	return 0;
}