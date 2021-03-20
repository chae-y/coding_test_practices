class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        bfs(numbers, target, numbers[0], 1);
        bfs(numbers, target, -numbers[0], 1);
        return answer;
    }
    public void bfs(int[] numbers, int target, int sum, int i){
        if(i==numbers.length&&sum==target){
            answer++;
            return;
        }
        if(i==numbers.length)   return;
        bfs(numbers, target, sum+numbers[i], i+1);
        bfs(numbers, target, sum-numbers[i], i+1);
        return;
    }
}