#include<vector>
#include<iostream>
using namespace std;

int n,m;
int dp[100][100]={0,};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[100][100]={0,};

void go(int x, int y, vector<vector<int>>& maps){
    visited[x][y]=true;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n)   continue;
        if(ny<0||ny>=m)   continue;
        if(maps[nx][ny]&&!visited[nx][ny]){
            dp[nx][ny]=min(dp[nx][ny],dp[x][y]+1);
            go(nx,ny,maps);
        }
    }
    visited[x][y]=false;
}

int solution(vector<vector<int> > maps)
{
    n=maps.size();
    m=maps[0].size();
    fill_n(dp[0],10000,100);
    dp[0][0]=1;
    go(0,0,maps);
    if(dp[n-1][m-1]==100)   return -1;
    return dp[n-1][m-1];
}