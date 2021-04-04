#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    long long temp=0;
    int minus=1;
    vector<int> v;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='-'){
            minus=-1;
            continue;
        }
        if(s[i]==' '){
            v.push_back(temp*minus);
            temp=0; minus=1;
            continue;
        }
        temp=temp*10+s[i]-'0';
    }
    v.push_back(temp*minus);
    sort(v.begin(),v.end());
    answer+=to_string(v[0]);
    answer+=" ";
    answer+=to_string(v[v.size()-1]);
    return answer;
}