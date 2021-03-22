#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr(n+1);
    
    for(int i=2; i<n+1; i++){
        arr[i]=i;
    }
    
    for(int i=2; i<=n; i++){
        if(arr[i]==0)   continue;
        for(int j=i*2; j<=n; j=j+i){
            arr[j]=0;
        }
    }
    
    for(int i=2; i<=n; i++){
        if(arr[i]!=0)   answer++;
    }
    return answer;
}