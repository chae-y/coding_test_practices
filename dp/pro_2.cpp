#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> left(a.size());
    vector<int> right(a.size());
    int minL=a[0];
    for(int i=0; i<a.size(); i++){
        minL=min(minL,a[i]);
        left[i]=minL;
    }
    int minR=a[a.size()-1];
    for(int i=a.size()-1; i>=0; i--){
        minR=min(minR,a[i]);
        right[i]=minR;
    }
    for(int i=0; i<a.size(); i++){
        if(a[i]<=left[i] || a[i]<=right[i]) answer++;
    }
    return answer;
}