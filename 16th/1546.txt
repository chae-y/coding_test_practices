#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double N;;
	cin >> N;
	double sum = 0;
	double maxx = 0;
	for (int i = 0; i < N; i++) {
		double temp;
		cin >> temp;
		sum += temp;
		maxx = max(temp, maxx);
	}
	cout << sum * 100 / N / maxx;
	return 0;
}