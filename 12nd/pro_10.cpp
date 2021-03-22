#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=3; i<=n; i++){
        bool tmp=true;
        for(int j=2; j<=sqrt(i); j++){
            if(i%j==0){
                tmp=false; break;
            }
        }
        if(tmp){
            answer++;
        }
    }
    return answer;
}