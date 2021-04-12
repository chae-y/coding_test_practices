#include <iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string s)
{
    int answer = 1;
    vector<char> v(s.begin(), s.end());
    while(v.size()!=0){
        int tmp=v.size();
        for(int i=0; i<v.size()-1; i++){
            if(v[i]==v[i+1]){
                v.erase(v.begin()+i,v.begin()+i+2);
                break;
            }
        }
        
        if(tmp==v.size()){
           answer=0; break; 
        }
    }

    return answer;
}