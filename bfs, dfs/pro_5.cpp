#include <string>
#include <vector>

using namespace std;

bool visited[50]={0,};
int answer=52;

bool change(string s1, string s2){
    int temp=0;
    for(int j=0; j<s1.size(); j++){
        if(s1[j]==s2[j])   temp++;
    }
    if(temp==s1.size()-1) return true;
    return false;
}

void dfs(int n, string end, vector<string> words, int cnt){
    if(end==words[n]){
        printf("%d",cnt);
        answer=min(answer,cnt);
        return;
    }
    for(int i=0; i<words.size(); i++){
        if(change(words[i],words[n])&&!visited[i]){
            visited[i]=1;
            dfs(i,end,words,cnt+1);
            visited[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    for(int i=0; i<words.size(); i++){\
        if(change(begin,words[i])){
            visited[i]=1;
            dfs(i,target,words,1);
            visited[i]=0;
        }
    }
    
    if(answer==52)  answer=0;
    return answer;
}