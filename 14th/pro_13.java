import java.util.Arrays;

class Solution {
    public long solution(long n) {
        long answer = 0;
        int len = (int)Math.log10(n)+1;
        long[] arr = new long[len];
        int i=0;
        while(n/10!=0){
            arr[i]=n%10;
            n/=10;
            i++;
        }
        arr[i]=n%10;
        Arrays.sort(arr);
        for(int j=0; j<len; j++){
            answer+=arr[j]*Math.pow(10,j);
        }
        return answer;
    }
}