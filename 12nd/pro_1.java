import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Vector<Integer> v= new Vector<Integer>();
        int cnt =-1;
        int current_t =0;
        for(int i=0; i<progresses.length; i++){
            int time=(100-progresses[i])/speeds[i];
            if((100-progresses[i])%speeds[i]!=0) time++;
            if(current_t>=time){
                v.set(cnt,v.get(cnt)+1);
            }else{
                cnt++;
                current_t=time;
                v.add(1);
            }
        }
        int[] answer = new int[v.size()];
        for(int i=0; i<v.size(); i++){
            answer[i]=v.get(i);
        }
        return answer;
    }
}