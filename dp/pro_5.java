import java.util.Arrays;

class Solution {
    public int solution(int n, int[] money) {
        Arrays.sort(money);
        
        int [] dp = new int[n+1];
        for(int i=0; i<=n; i++){
            if(i%money[0]==0)   dp[i]=1;
            else dp[i]=0;
        }
        
        for(int i=1; i<money.length; i++){
            for(int j=money[i];j<=n; j++){
                dp[j]+=dp[j-money[i]];
                dp[j]%=1000000007;
            }
        }
        
        return dp[n]%1000000007;
    }
}