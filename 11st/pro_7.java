import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> s= new Stack<>();
        for(int i=0; i<moves.length; i++){
        int j=0;
        while(j<board.length&&board[j][moves[i]-1]==0){
            j++;
        }
        if(j<board.length){
            if(!s.empty()&&s.peek()==board[j][moves[i]-1]){
                s.pop(); answer+=2;
            }
            else    s.push(board[j][moves[i]-1]);
            board[j][moves[i]-1]=0;
        }
    }
        return answer;
    }
}