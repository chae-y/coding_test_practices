#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;


vector<int> v[8];
set<string> s;
int visited[8]={0,};

void dfs(int i, int N){
    if(i==N){
        string temp="";
        for(int j=0;j<8;j++)
            if(visited[j]) temp+=to_string(j);
        s.insert(temp);
        return;
    }
    for(int j=0; j<v[i].size(); j++){
        if(visited[v[i][j]])    continue;
        visited[v[i][j]]=1;
        dfs(i+1,N);
        visited[v[i][j]]=0;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    for(int i=0; i<banned_id.size(); i++){
        for(int j=0; j<user_id.size(); j++){
            if(banned_id[i].size()==user_id[j].size()){
                bool same=true;
                for(int k=0; k<user_id[j].size(); k++){
                    if(banned_id[i][k]=='*'){
                        continue;
                    }else if(banned_id[i][k]==user_id[j][k]){
                        continue;
                    }else{
                        same=false;
                    }
                }
                if(same){
                    v[i].push_back(j);
                }
            }
        }
    }
    dfs(0,banned_id.size());
    return s.size();
}