#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    vector<int> v;
    int* order = new int[priorities.size()];
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
        v.push_back(priorities[i]);
    }
    sort(v.begin(), v.end(), desc);
    for (int i = 0; i < v.size(); i++) {
        int front_p = q.front().first;//우선순위
        int front_i = q.front().second;//위치
        while (front_p != v[i]) {
            q.pop();
            q.push(make_pair(front_p, front_i));
            front_p = q.front().first;
            front_i = q.front().second;
        }
        order[q.front().second] = i;
        q.pop();
    }
    return order[location] + 1;
}