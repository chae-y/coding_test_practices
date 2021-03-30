#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,vector<int>>> v;
    int cnt;
    vector<int> temp;
    int num=0;
    for(int i=1; i<s.size()-1; i++){
        if(s[i]=='{'){
            cnt=0;
            temp.clear();
            continue;   
        }
        if(s[i]=='}'){
            temp.push_back(num);
            cnt++;
            num=0;
            v.push_back({cnt,temp});
            continue;   
        }
        if(s[i]==','){
            temp.push_back(num);
            num=0;
            cnt++;
            continue;   
        }
        num*=10;
        num+=(s[i]-'0');
    }
    
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].second.size(); j++){
            if(find(answer.begin(), answer.end(), v[i].second[j])==answer.end())
                answer.push_back(v[i].second[j]);
        }
    }
    return answer;
}