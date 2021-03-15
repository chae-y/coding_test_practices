import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> heap = new PriorityQueue();
        for(int i : scoville){
            heap.add(i);
        }
        while(heap.peek()<=K){
            if(heap.size()==1)  return -1;  
            int a= heap.poll();
            int b= heap.poll();
            
            int sum = a+(b*2);
            
            heap.add(sum);
            answer++;
        }
        return answer;
    }
}