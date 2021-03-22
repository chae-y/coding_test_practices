#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> v;
    for(int i=0; i<new_id.size(); i++){
        if('A'<=new_id[i]&&'Z'>=new_id[i]){//1번 조건
            new_id[i]=new_id[i]-'A'+'a';
        }
        if(!(('a'<=new_id[i]&&'z'>=new_id[i])||
           new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.'||
           ('0'<=new_id[i]&&'9'>=new_id[i]))){//2번 조건
            continue;
        }
        if(v.size()!=0&&new_id[i]=='.'&&v[v.size()-1]=='.'){//3번 조건
            continue;
        }
        if(v.size()==0&&new_id[i]=='.'){//4-1
            continue;
        }
        v.push_back(new_id[i]);
    }
    for(int i=v.size()-1; i>=0; i--){//4-2
        if(v[i]=='.'){
            v.erase(v.begin()+i);
        }else{
            break;
        }
    }
    if(v.size()==0){//5번 조건
        v.push_back('a');v.push_back('a');v.push_back('a');
    }
    if(v.size()>15){//6번 조건
        v.erase(v.begin()+15,v.end());
    }
    for(int i=v.size()-1; i>=0; i--){//6-2
        if(v[i]=='.'){
            v.erase(v.begin()+i);
        }else{
            break;
        }
    }
    if(v.size()<3){//7번조건
        while(v.size()<3){
            v.push_back(v[v.size()-1]);
        }
    }
    //출력
    for(int i=0; i<v.size(); i++){
        answer+=v[i];
    }
    return answer;
}