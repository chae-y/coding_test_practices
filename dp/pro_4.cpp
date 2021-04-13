#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int DP[100000][4]={0,};
    int answer = 0;

    for(int i=0; i<4; i++){
        DP[0][i]=land[0][i];
    }
    for(int i=1; i<land.size(); i++){
        for(int j=0; j<4; j++){
            switch(j){
                case 0:
                    DP[i][j]=max(max(DP[i-1][1],DP[i-1][2]),DP[i-1][3])+land[i][j];
                    break;
                case 1:
                   DP[i][j]=max(max(DP[i-1][0],DP[i-1][2]),DP[i-1][3])+land[i][j];
                    break;
                case 2:
                    DP[i][j]=max(max(DP[i-1][1],DP[i-1][0]),DP[i-1][3])+land[i][j];
                    break;
                case 3:
                    DP[i][j]=max(max(DP[i-1][1],DP[i-1][2]),DP[i-1][0])+land[i][j];
                    break;
            }
        }
    }
    
    for(int i=0; i<4; i++){
        answer=max(max(DP[land.size()-1][0],DP[land.size()-1][1]),max(DP[land.size()-1][2],DP[land.size()-1][3]));
    }

    return answer;
}