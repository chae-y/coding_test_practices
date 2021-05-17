import java.util.Arrays;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int zero=0;
        int sucess=0;
        Arrays.sort(win_nums);
        for(int n : lottos){
            if(n==0){
                zero++;
                continue;
            }
            if(Arrays.binarySearch(win_nums,n)>=0)
                sucess++;
        }
        answer[1]=6-sucess+1;
        answer[0]=6-sucess-zero+1;
        for(int i=0; i<2; i++){
            if(answer[i]==7)    answer[i]=6;
        }
        return answer;
    }
}