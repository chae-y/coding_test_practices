#include <string>
#include <vector>

using namespace std;

bool visited[200]={0,};

void dfs(int n, vector<vector<int>> computers){
    visited[n]=1;
    for(int i=0; i<computers[n].size(); i++){
        if(!visited[i]&&computers[n][i]) dfs(i,computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<computers.size(); i++){
        if(visited[i]) continue;
        dfs(i,computers);
        answer++;
    }
    return answer;
}