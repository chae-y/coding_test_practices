#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nn=0;

bool compare(string s1, string s2){
    if(s1[nn]>s2[nn])   return false;
    else if (s1[nn]<s2[nn]) return true;
    else return s1<s2;
}

vector<string> solution(vector<string> strings, int n) {
    nn=n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}