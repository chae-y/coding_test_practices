#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    
    int a = v[0][0]-v[1][0];
    int b = v[0][0]-v[2][0];
    int c = v[1][0]-v[2][0];
    int aa = v[0][1]-v[1][1];
    int bb = v[0][1]-v[2][1];
    int cc = v[1][1]-v[2][1];
    
    if(a*b+aa*bb==0){
        ans.push_back(v[2][0]-a);
        ans.push_back(v[2][1]-aa);
    }
    if(a*c+aa*cc==0){
        ans.push_back(v[0][0]-c);
        ans.push_back(v[0][1]-cc);
    }
    if(c*b+cc*bb==0){
        ans.push_back(b+v[1][0]);
        ans.push_back(bb+v[1][1]);
    }

    return ans;
}