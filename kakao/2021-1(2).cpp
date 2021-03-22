#include <string>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.size(); i++){
        if('A'<=new_id[i]&&'Z'>=new_id[i]){//1번 조건
            new_id[i]=new_id[i]-'A'+'a';
        }
        if(!(('a'<=new_id[i]&&'z'>=new_id[i])||
            new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.'||
            ('0'<=new_id[i]&&'9'>=new_id[i]))){//2번 조건
            continue;
        }
        if(answer.size()!=0&&new_id[i]=='.'&&answer.back()=='.'){//3번 조건
            continue;
        }
        answer+=new_id[i];
    }
    if(answer.front()=='.'){//4-1
            answer.erase(answer.begin());
    }
    if(answer.back()=='.'){//4-2
            answer.erase(answer.end()-1);
    }
    if(answer.size()==0){//5번 조건
        answer="aaa";
    }
    if(answer.size()>15){//6번 조건
        answer.erase(answer.begin()+15,answer.end());
    }
    if(answer.back()=='.'){//6-2
            answer.erase(answer.end()-1);
    }
    while(answer.size()<3){//7번조건
        answer.push_back(answer[answer.size()-1]);
    }
    
    return answer;
}