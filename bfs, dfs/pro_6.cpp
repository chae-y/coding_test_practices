#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int n,m;
int dp[100][100]={0,};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[100][100]={0,};

int solution(vector<vector<int> > maps)
{
    n=maps.size();
    m=maps[0].size();
    queue<pair<int,int>> q;
    dp[0][0]=1;
    visited[0][0]=true;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n)   continue;
            if(ny<0||ny>=m)   continue;
            if(maps[nx][ny]&&!visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny]=true;
                dp[nx][ny]=dp[x][y]+1;
            }
        }
    }
    if(!visited[n-1][m-1])   return -1;
    return dp[n-1][m-1];
}