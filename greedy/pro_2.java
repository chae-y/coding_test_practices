import java.util.Arrays;
import java.util.Comparator;

class Solution {
    
    int parent[] = new int[100];
    
    public int find_p(int n){
        if(n==parent[n])    return n;
        else{
            return parent[n]=find_p(parent[n]);
        }
    }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        Arrays.sort(costs, new Comparator<int[]>(){
            @Override
            public int compare(int[] a1, int[] a2){
                Integer a=a1[2];
                Integer b=a2[2];
                return a.compareTo(b);
            }
        });
        for(int i=0; i<costs.length; i++){
            int p1=find_p(costs[i][0]);
            int p2=find_p(costs[i][1]);
            if(p1==p2){
               continue;
            }
            parent[p1]=p2;
            answer+=costs[i][2];
        }
        return answer;
    }
}