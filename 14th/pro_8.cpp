#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    int lower[26]={0,};
    bool use[26]={false,};
    for(int i=0; i<sentence.size(); i++){
        if(sentence[i]==' '){//공백있으면 실패
            return "invalid";
        }
        if('a'<=sentence[i]&&sentence[i]<='z')
            lower[sentence[i]-'a']++;
    }
    
    char start_a=' ';
    string tmp="";
    vector<string> result;
    
    for(int i=0; i<sentence.size(); i++){
        start_a=sentence[i];

        if('a'<=start_a&&start_a<='z'){//2번 규칙(+1번 규칙)
            if(use[start_a-'a'])    return "invalid";
            use[start_a-'a']=true;
            if(lower[start_a-'a']==2){
                if(sentence[i+1]==start_a)  return "invalid";
                i++;    
                while(sentence[i]!=start_a){
                    if(start_a!=sentence[i+1]&&'a'<=sentence[i+1]&&sentence[i+1]<='z'){//2+1번규칙
                        char temp=sentence[i+1];
                        if(use[temp-'a'])    return "invalid";
                        use[temp-'a']=true;
                        for(;i<sentence.size(); i+=2){
                            tmp+=sentence[i];
                            if(sentence[i+1]!=temp) break;
                        }
                        i++;
                        if(sentence[i]!=start_a){
                            return "invalid";
                        } 
                    }
                    else{
                        tmp+=sentence[i]; i++;
                    }
                }
                result.push_back(tmp);
                tmp="";
            }
            else    return "invalid";
        }
        if('A'<=start_a&&start_a<='Z'){//1번 규칙
            if(i>=sentence.size()-1||lower[sentence[i+1]-'a']==2){//1개짜리
                tmp+=start_a;
            }
            else if('A'<=sentence[i+1]&&sentence[i+1]<='Z'){//아무규칙없는경우
                while('A'<=sentence[i]&&sentence[i]<='Z'){
                    tmp+=sentence[i];
                    i++;
                }
                if(i+2<sentence.size()&&sentence[i+2]==sentence[i]){
                    tmp.pop_back();
                    i--;
                } 
                i--;
            }
            else{
                char temp=sentence[i+1];
                if(use[temp-'a'])    return "invalid";
                use[temp-'a']=true;
                for(;i<sentence.size(); i+=2){
                    if(!('A'<=sentence[i]&&sentence[i]<='Z'))  return "invalid";
                    tmp+=sentence[i];
                    if(sentence[i+1]!=temp) break;
                }
            }
            
            result.push_back(tmp);
            tmp="";
        }
    }
    
    
    for(int i=0; i<result.size(); i++){
        answer+=result[i];
        if(i!=result.size()-1)  answer+=" ";
    }
    
    return answer;
}