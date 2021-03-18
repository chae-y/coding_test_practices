class Solution {
    int answer = -1;
    public int solution(int N, int number) {
        dfs(N,number,0,0);
        return answer;
    }
    public void dfs(int N, int number, int cnt, int prev){
        int temp_N=N;
        if(cnt>8){
            answer=-1;
            return;
        }
        if(number == prev) {
            if(answer==-1||answer>cnt)  answer=cnt;
            return;
        }
        for(int i=0; i<8-cnt; i++){
            dfs(N,number,cnt+i+1,prev-temp_N);
            dfs(N,number,cnt+i+1,prev+temp_N);
            dfs(N,number,cnt+i+1,prev*temp_N);
            dfs(N,number,cnt+i+1,prev/temp_N);
            
            temp_N = increaseNumber(temp_N,N);
        }
    }
    public int increaseNumber(int value, int N){
        return value*10+N;
    }
}