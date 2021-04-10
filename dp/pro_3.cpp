#include <string>
#include <vector>

using namespace std;

int f(int n){
    int dp[60001]={0,1,2,0,};
    for(int i=3; i<=n; i++){
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
    }
    return dp[n]%1000000007;
}

int solution(int n) {
    int answer = f(n);
    return answer;
}