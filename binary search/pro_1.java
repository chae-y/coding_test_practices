import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        long right = (long)times[times.length-1]*n;
        long left = times[0];
        long answer = right;
        while(right>=left){
            long mid =(right+left)/2;
            long sum=0;
            for(int time: times){
                sum+=mid/time;
            }
            if(sum<n){
                left= mid+1;
            }
            else{
                right=mid-1;
                answer=mid;
            }
        }
        return answer;
    }
}