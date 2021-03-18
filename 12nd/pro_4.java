class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int i=0,j=0;
        for(i=3; i <= (int) (brown + 4) / 2; i++){
            j = ((4+brown)/2)-i;
            if(i>=j && i*j==yellow+brown) break;
        }
        answer[0]=i;
        answer[1]=j;
        return answer;
    }
}