import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        while(answer<scoville.length-1){
            Arrays.sort(scoville);
            if(scoville[answer]>=K) return answer;
            answer++;
            scoville[answer]=scoville[answer-1]+scoville[answer]*2;
        }
        if(scoville[answer]>=K) return answer;
        return -1;
    }
}