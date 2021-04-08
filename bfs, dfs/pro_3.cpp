#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited(10000, false);
vector<string> answer;
bool first=true;

void dfs(string start, vector<vector<string>> tickets,vector<string>& temp){
    temp.push_back(start);
    if(temp.size()==tickets.size()+1&&first){
        answer=temp;
        first=false;
    }
    for(int i=0; i<tickets.size(); i++){
        if(start==tickets[i][0]&&!visited[i]){
            visited[i]=true;
            dfs(tickets[i][1],tickets,temp);
            visited[i]=false;
            temp.pop_back();
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> temp;
    sort(tickets.begin(),tickets.end());
    dfs("ICN",tickets,temp);
    return answer;
}