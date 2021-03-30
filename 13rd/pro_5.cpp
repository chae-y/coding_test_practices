#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' ')  continue;
        int temp=s[i]+n;
        if('a'<=s[i]&&s[i]<='z'){
            if(temp>'z')   temp-=26;
        }
        if('A'<=s[i]&&s[i]<='Z'){
            if(temp>'Z')   temp-=26;
        }
        answer[i]=temp;
    }
    return answer;
}