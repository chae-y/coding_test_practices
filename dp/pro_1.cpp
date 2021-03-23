#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[101][101]={0,};
    for(int i=0; i<puddles.size(); i++){
        map[puddles[i][0]][puddles[i][1]]=-1;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(i==1&&j==1)  map[i][j]=1;
            else if(map[i][j]!=-1)
                map[i][j]=(map[i-1][j]+map[i][j-1])% 1000000007;
            else map[i][j]=0;
        }
    }
    return map[m][n]%1000000007;
}