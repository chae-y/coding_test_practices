import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        PriorityQueue<Integer> pq1 = new PriorityQueue<>();//min
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(Collections.reverseOrder());//max
        for(int i=0; i<operations.length; i++){
            if(operations[i].charAt(0)=='I'){
                int temp = Integer.parseInt(operations[i].substring(2));
                pq1.add(temp);
                pq2.add(temp);
            }
            else{
                if(pq1.isEmpty())   continue;
                int rm;
                if(operations[i].charAt(2)=='1'){
                    rm = pq2.poll();
                    pq1.remove(rm);
                }else{
                    rm = pq1.poll();
                    pq2.remove(rm);
                }
            }
        }
        if(pq1.isEmpty()) return answer;
        else{
            answer[0]=pq2.peek();
            answer[1]=pq1.peek();
        }
        return answer;
    }
}