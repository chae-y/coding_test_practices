#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string solution(vector<string> participaint, vector<string> completion) {
	sort(participaint.begin(), participaint.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < completion.size(); i++) {
		if(participaint[i]!=completion[i])
			return participaint[i];
	}
	return participaint[completion.size()];
}

int main() {
	vector<string> participaint;
	vector<string> completion;

	int N;
	string temp;
	for(int i=0; i<N; i++){
		cin >> temp;
		participaint.push_back(temp);
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> temp;
		completion.push_back(temp);
	}

	cout<<solution(participaint, completion);

	return 0;
}
/*
1) vector participaint,completion 받기
2) 2개 정렬 후 같지 않으면 출력
*/

