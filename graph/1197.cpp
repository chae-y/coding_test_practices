#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int,pair<int,int>>> vec;
int sum = 0;
int parent[10001] = { 0, };

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

bool edge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
        return true;
    }
    return false;
}

int main() {
    int v,e;
    cin >> v>>e;
    for (int i = 0; i < e; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        vec.push_back({ x,{a,b} });
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < vec.size(); i++) {
        if(edge(vec[i].second.first, vec[i].second.second)) sum+=vec[i].first;
    }

    cout << sum;
    return 0;
}