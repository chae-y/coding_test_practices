class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        int size=s.length();
        if(size!=4&&size!=6)  answer=false;
        for(char c : s.toCharArray()){
            if('0'<=c&&c<='9')    continue;
            answer=false;
        }
        return answer;
    }
}