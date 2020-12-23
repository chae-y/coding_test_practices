#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<string> stu, result;
set<string> set1;

int main() {
	int sucess, N;
	cin >> sucess >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		stu.push_back(temp);
	}
	for (int i = N - 1; i >= 0; i--) {
		string st = stu[i];
		if (set1.find(st) == set1.end()) {
			set1.insert(st);
			result.push_back(st);
		}
	}
	int size = result.size();
	for (int i = size-1; i >=size-sucess && i>=0; i--) {
		cout << result[i]<<endl;
	}
}