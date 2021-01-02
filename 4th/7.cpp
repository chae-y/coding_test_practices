#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int* stu = new int[N];
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		stu[i] = temp;
	}
	int b, c;
	cin >> b >> c;
	long long tea = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		if (stu[i] <= b)	temp = 1;
		else
		{
			temp = 1 + (stu[i] - b) / c;
			if (((stu[i] - b) % c )>0)	temp++;
		}
		tea += temp;
	}
	cout << tea;
	return 0;
}