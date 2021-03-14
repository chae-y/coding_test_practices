import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> q= new LinkedList<>();
        int time=1;
        q.add(truck_weights[0]);
        int t_weight=truck_weights[0];
        int i=1;
        while(i<truck_weights.length){
            while(q.size()!=bridge_length&&i<truck_weights.length&&t_weight+truck_weights[i]<=weight){
                q.add(truck_weights[i]);
                t_weight+=truck_weights[i];
                i++;
                time++;
            }
            while(i<truck_weights.length&&q.size()!=bridge_length){
                q.add(0);
                time++;
            }
            if(q.size()==bridge_length){
                int pop = q.poll();
                t_weight-=pop;
            }
            // while(q.size()==bridge_length&&i==bridge_length){
            //     int pop = q.poll();
            //     t_weight-=pop;
            // }
        }
        return time+bridge_length;
    }
}