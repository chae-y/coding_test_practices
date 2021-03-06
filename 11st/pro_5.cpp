#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int s=0;
    if(arr.size()==1){
        answer.push_back(-1);
        return answer;
    }
    for(int i=1; i<arr.size(); i++){
        if(arr[s]>arr[i])    s=i;
    }
    for(int i=0; i<arr.size(); i++){
        if(i!=s)    answer.push_back(arr[i]);
    }
    return answer;
}