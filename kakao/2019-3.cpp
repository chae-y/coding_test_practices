#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> parent;

long long find(long long x){
    if(0==parent[x])    return x;
    return parent[x]=find(parent[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    int n = room_number.size();
    for(int i=0; i<n; i++){
        if(parent[room_number[i]]==0){
            answer.push_back(room_number[i]);
            parent[room_number[i]]=find(room_number[i]+1);
        }else{
            long long next = find(room_number[i]);
            answer.push_back(next);
            parent[next]=find(next+1);
        }
    }
    return answer;
}
