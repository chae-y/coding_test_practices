import java.util.*;

class Solution {
    public int solution(String numbers) {
        int answer = 0;
        HashSet<Integer> set = new HashSet<>();
        permutation("",numbers,set);
        
        while(set.iterator().hasNext()){
            int a = set.iterator().next();
            set.remove(a);
            if(a==2) answer++;
            else if(isPrime(a)) answer++;
        }
        return answer;
    }
    
    public void permutation(String prefix, String str, HashSet<Integer> set){
        int n= str.length();
        if(!prefix.equals("")){
             set.add(Integer.valueOf(prefix));
        }
        for(int i=0;i<n; i++){
            permutation(prefix+str.charAt(i), str.substring(0,i)+str.substring(i+1,n),set);
        }
    }
    
    public boolean isPrime(int n){
        if(n==0||n==1)  return false;
        for(int i=2;i<=(int)Math.sqrt(n); i++){
            if(n%i==0)  return false;
        }
        return true;
    }
}