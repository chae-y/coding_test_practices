#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int,int>> v; //돌 숫자, 돌위치
vector<pair<int,int>> parent; //맨 앞 돌, 연결 된 수

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first)    return a.first<b.first;
    else return a.second>b.second;
}

int find(int n){
    if(n==parent[n].first)
        return n;
    else return parent[n].first=find(parent[n].first);
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int len = stones.size();
    for(int i=0; i<len; i++){
        v.push_back({stones[i],i});
         if(stones[i]==0&&i!=0){
             int p=find(i-1);
             parent.push_back({p,parent[p].second++});
             if(parent[p].second>k)    return 0;
             if(stones[p]==0&&parent[p].second==k) return 0;
         }
        else    parent.push_back({i,1});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<len; i++){
        int n=v[i].second;//현재 돌
        //if(stones[n]==0&&parent[n].second>=k) return 0; 
        if(stones[n]==0) continue;
        if(n!=0&&stones[n-1]<stones[n]){
            parent[n].first=find(n-1);
            parent[parent[n].first].second+=parent[n].second;
            if(parent[parent[n].first].second>=k){
                return answer=v[i].first;
            }
        }  
        if(n!=len-1&&stones[n+1]<=stones[n]){
            parent[n+1].first=parent[n].first;
            parent[parent[n+1].first].second+=parent[n+1].second;
            if(parent[parent[n+1].first].second>=k){
                return answer=v[i].first;
            }
        }
    }
    return v[len-1].first;
}