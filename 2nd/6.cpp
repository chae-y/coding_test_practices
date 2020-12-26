#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

string word;
map<string, int> m;
int k=1;

int exist(string s, int i) {
	if (m.count(s)) {
		i++;
		s += word[i+1];
		i = exist(s, i);
	}
	else {
		m[s] = k;
		k++;
		cout << m[s.substr(0,s.size()-1)]<<endl;
		return i;
	}
	return i;
}

int main() {
	cin >> word;
	transform(word.begin(), word.end(), word.begin(), ::toupper);
	for (char c = 'A'; c <= 'Z';c++) {
		string s="";
		s += c;
		m[s] = k;
		k++;
	}
	for (int i = 0; i < word.length(); i++) {
		string str = "";
		str += word[i];
		if(i!=word.length())
			str += word[i + 1];
		i=exist(str, i);
	}

	return 0;
}