#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int,int>> st={{0,1},{0,2},{0,3}};
    int an[3][10]={{1,2,3,4,5,},{2,1,2,3,2,4,2,5,},{3,3,1,1,2,2,4,4,5,5}};
    //12345, 21232425, 3311224455
    for(int i=0; i<answers.size(); i++){
        if(an[0][i%5]==answers[i]) st[0].first++;
        if(an[1][i%8]==answers[i]) st[1].first++;
        if(an[2][i%10]==answers[i]) st[2].first++;
    }
    sort(st.begin(),st.end());
    int maxx=st[2].first; 
    answer.push_back(st[2].second);
    for(int i=1; i>=0; i--){
        if(maxx!=st[i].first)   break;
        else    answer.push_back(st[i].second);
    }
    sort(answer.begin(),answer.end());
    return answer;
}