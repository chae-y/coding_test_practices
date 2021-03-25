#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends="ACFJMNRT";
    do{
        bool photo;
        for(int i=0; i<n; i++){
            char a=data[i][0];
            char b=data[i][2];
            char com=data[i][3];
            int num=data[i][4]-'0'+1;
            int dif=friends.find(a)-friends.find(b);
            photo=false;
            switch(com){
                case '=':
                    photo=(abs(dif)==num);
                    break;
                case '>':
                    photo=(abs(dif)>num);
                    break;
                case '<':
                    photo=(abs(dif)<num);
                    break; 
            }
            if(photo==false) break;
        }
        if(photo)   answer++;
    }while(next_permutation(friends.begin(),friends.end()));
    return answer;
}