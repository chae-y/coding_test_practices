class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int[] dp1 = new int[triangle.length];
        int[] dp2 = new int[triangle.length];
        dp1[0]=triangle[0][0];
        for(int i=1; i<triangle.length; i++){
            for(int j=0; j<triangle[i].length; j++){
                if(j==0){
                    if(i%2==1)  dp2[j]=dp1[j]+triangle[i][j];
                    else dp1[j]=dp2[j]+triangle[i][j];
                }
                else if(i%2==1)  dp2[j]=Math.max(dp1[j-1],dp1[j])+triangle[i][j];
                else dp1[j]=Math.max(dp2[j-1],dp2[j])+triangle[i][j];
            }
        }
        if(triangle.length%2==0){
            for(int i=0; i<triangle.length; i++){
                answer=Math.max(answer,dp2[i]);
            }
        }
        else{
            for(int i=0; i<triangle.length; i++){
                answer=Math.max(answer,dp1[i]);
            }
        }
        return answer;
    }
}