import java.util.*;

class Solution {
    public int[] solution(int n, long k) {
        int[] answer = new int[n];
        
        long len=1;
        for(int i=2; i<=n; i++){
            len*=i;
        }
        
        Vector<Integer> v= new Vector<Integer>();
        for(int i=0; i<=n; i++){
            v.add(i);
        }
        
        long kk=0;
        for(int i=0; i<n; i++){
            int nn=n-i;
            len/=nn;
            for(int j=1; j<=n-i; j++){
                if(k<=len*j+kk){
                    answer[i]=v.get(j);
                    v.remove(j);
                    kk+=len*(j-1);
                    break;
                }
            }
        }
        
        return answer;
    }
}