import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer=0;
        Arrays.sort(citations);
        int i=citations.length;
        for(int n :  citations){
            answer = Math.max(answer,Math.min(n,i--));
        }
        return answer;
    }
}