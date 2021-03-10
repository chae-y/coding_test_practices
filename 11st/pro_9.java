import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] st = {0,0,0};
        int[][] an = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
        for(int i=0; i<answers.length; i++){
        if(an[0][i%5]==answers[i]) st[0]++;
        if(an[1][i%8]==answers[i]) st[1]++;
        if(an[2][i%10]==answers[i]) st[2]++;
        }
        int maxx=Math.max(st[0],Math.max(st[1],st[2]));
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<3; i++){
            if(st[i]==maxx) list.add(i+1);
        }
        int[] answer = new int[list.size()];
        int k=0;
        for(int l:list){
            answer[k++]=l;
        }
        return answer;
    }
}