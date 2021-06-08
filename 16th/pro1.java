class Solution {
    public String solution(String s) {
        String answer = "";
        int n=1;
        for(int i=0; i<s.length(); i++){
            char c=s.charAt(i);
            if(c==' '){
                n=0;
                answer+=c;
            }
            else if(n%2==0){
                answer+=Character.toLowerCase(c);
            }
            else{
                answer+=Character.toUpperCase(c);
            }
            n++;
        }
        return answer;
    }
}