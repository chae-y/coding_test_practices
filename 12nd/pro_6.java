class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int len=number.length();
        int cnt=len-k;
        int post_max=-1;
        while(cnt>0){
            int max=post_max+1;
            for(int i=post_max+1; i<=len-cnt; i++){
                if(number.charAt(i)=='9'){
                    max=i; break;
                }
                if(number.charAt(max)<number.charAt(i)) max=i;
            }
            answer+=number.charAt(max);
            post_max=max;
            cnt--;
        }
        return answer;
    }
}