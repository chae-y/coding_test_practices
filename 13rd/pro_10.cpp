#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001] ={0,};
    
    int x=0,y=1;
    int state=1;
    int num=0;
    
    for(int i=0; i<n; i++){
        switch (state){
            case 1:
                for(int j=i; j<n; j++)
                    arr[++x][y]=++num;
                state=2;
                break;
            case 2:
                for(int j=i; j<n; j++)
                    arr[x][++y]=++num;
                state=3;
                break;
            case 3:
                for(int j=i; j<n; j++)
                    arr[--x][--y]=++num;
                state=1;
                break;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}