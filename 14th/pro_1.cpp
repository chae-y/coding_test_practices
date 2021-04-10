#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(int i=2; i<=n; i++){
        if(n%i==0&&i%2==1)  answer++;
    }

    return answer;
}