#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> solution(vector<int> v1, vector<int> v2) {
	vector <string> answer;
	for (int i = 0; i < v1.size(); i++) {
		int temp = v1[i] | v2[i];
		string st = "";
		for (int j = 0; j < v2.size(); j++) {
			if (temp % 2 == 0)
				st += " ";
			else
				st += "#";
			temp = 
				temp >> 1;
		}
		reverse(st.begin(), st.end());
		answer.push_back(st);
	}
	return answer;
}

vector<int> v1, v2, v3;

int main() {
	int N;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v1.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v2.push_back(temp);
	}
	vector<string> v3 = solution(v1,v2);
	for (int i = 0; i < N; i++) {
		cout << v3[i] << endl;
	}

	return 0;
}