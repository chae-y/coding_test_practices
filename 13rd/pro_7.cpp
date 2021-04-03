#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int n=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='p'||s[i]=='P')      n++;
        if(s[i]=='y'||s[i]=='Y')      n--;
    }
    if(n!=0) answer=false;
    return answer;
}