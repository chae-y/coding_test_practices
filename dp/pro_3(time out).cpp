#include <string>
#include <vector>

using namespace std;

int recursion(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n>2) return (recursion(n-1)+recursion(n-2))%1000000007;
}

int solution(int n) {
    int answer = recursion(n);
    return answer;
}