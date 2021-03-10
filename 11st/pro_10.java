import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> s = new Stack<>();
        s.push(0);
        for(int i=1; i<prices.length; i++){
            while(!s.empty()&&prices[s.peek()]>prices[i]){
                answer[s.peek()]=i-s.peek();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            answer[s.peek()]=prices.length-s.peek()-1;
            s.pop();
        }
        return answer;
    }
}