#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
   
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1; i<s.size(); i++){
        if(!stk.empty()&&stk.top()==s[i]) stk.pop();
        else stk.push(s[i]);
    }
    if(stk.size()==0)   answer++;

    return answer;
}