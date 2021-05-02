#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b){
    if('A'<=a<='Z'){
        a=a+'z';
    }
    if('A'<=b<='Z'){
        b=b+'z';
    }
    return a>b;
}

string solution(string s) {
    sort(s.begin(),s.end(),compare);
    return s;
}