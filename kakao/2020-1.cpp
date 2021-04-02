#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string s){
    int ch=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(')   ch++;
        if(s[i]==')')   ch--;
        if(ch<0)    return false;
    }   
    return true;
}

string recursion(string s){
    //1
    if(s=="")   return s;
    //2
    string u,v;
    int cnt=0;
    int i=0;
    do{
        if(s[i]=='(')   cnt++;
        if(s[i]==')')   cnt--;
        i++;
    }while(cnt!=0);
    u=s.substr(0,i);
    v=s.substr(i);
    //3
    if(check(u)) return u+recursion(v);//3-1
    //4
    else{
        string temp{"("};//4-1
        temp+=recursion(v)+")";//4-2,3
        u=u.substr(1,u.length()-2);//4-4
        for(int i=0; i<u.size(); i++){
            if(u[i]=='(')   temp+=')';
            else    temp+='(';
        }
        return temp;//4-5
    }
}

string solution(string p) {
    if(check(p)) return p;
    return recursion(p);
}