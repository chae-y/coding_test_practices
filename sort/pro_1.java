import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String num[] = new String[numbers.length];
        int j=0;
        for(int i : numbers){
            num[j]=Integer.toString(i);
            j++;
        }
        Arrays.sort(num, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                return (s2+s1).compareTo(s1+s2);
            }
        });//Arrays.sort(num,(s1,s2)->(s2+s1).compareTo(s1+s2));도 가능
        if(num[0].equals("0"))  return "0";
        for(String i : num){
            answer+=i;
        }
        return answer;
    }
}