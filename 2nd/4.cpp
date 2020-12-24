#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
#include<string>

using namespace std;

int main() {
	string st1, st2;
	int n=0, u=0;
	map<string, int> m;
	map<string, int>::iterator it;
	getline(cin, st1);
	getline(cin, st2);
	for (int i = 0; i < st1.length() - 1; i++) {
		if (isalpha(st1[i]) == 0 || isalpha(st1[i + 1]) == 0)
			continue;
		else {
			string str;
			str = toupper(st1[i]);
			str += toupper(st1[i + 1]);
			if (m.count(str))
				m[str]++;
			else 
				m[str]=1;
			u++;
			cout << str << "|";
		}
	}
	for (int i = 0; i < st2.length() - 1; i++) {
		if (isalpha(st2[i]) == 0 || isalpha(st2[i + 1]) == 0)
			continue;
		else {
			string str;
			str = toupper(st2[i]);
			str += toupper(st2[i + 1]);
			if (m[str]!=0) {
				m[str]--;
				n++;
			}
			else {
				u++;
			}
		}
	}
	double result = 65536;
	if(u!=0)
		result = n * 65536 /u;
	cout << int(result);
	return 0;
}