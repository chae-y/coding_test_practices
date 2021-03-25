#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int remove=0;
    int cnt=0;
    while(s!="1"){
        int remain=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                remove++;
            }else{
                remain++;
            } 
        }
        s.clear();
        //2진법 만들기
        while(remain!=0){
            s+=to_string(remain%2);
            remain/=2;
        }
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(remove);
    return answer;
}