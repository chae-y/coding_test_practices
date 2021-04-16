#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int ud[11][11]={0,};//음수부분은 6-10
    int lr[11][11]={0,};
    int x=0, y=0;
    for(int i=0; i<dirs.size(); i++){
        if(dirs[i]=='L'){
            if(x<=-5) continue;
            if(!lr[x>=0?x:x+11][y>=0?y:y+11]) answer++;
            lr[x>=0?x:x+11][y>=0?y:y+11]=1;
            x--;
        }
        if(dirs[i]=='R'){
            if(x>=5) continue;
            x++;
            if(!lr[x>=0?x:x+11][y>=0?y:y+11]) answer++;
            lr[x>=0?x:x+11][y>=0?y:y+11]=1;
        }
        if(dirs[i]=='U'){
            if(y>=5) continue;
            y++;
            if(!ud[x>=0?x:x+11][y>=0?y:y+11]) answer++;
            ud[x>=0?x:x+11][y>=0?y:y+11]=1;
        }
        if(dirs[i]=='D'){
            if(y<=-5) continue;
            if(!ud[x>=0?x:x+11][y>=0?y:y+11]) answer++;
            ud[x>=0?x:x+11][y>=0?y:y+11]=1;
            y--;
        }
    }
    return answer;
}