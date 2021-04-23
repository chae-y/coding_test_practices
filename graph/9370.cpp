#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int s;
vector<pair<int, int>> v[50000];
int min_d[50000];
vector<int> answer;

int dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,s });
    min_d[s] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (min_d[cur] < cost)    continue;
        for (int i = 0; i < v[cur].size(); i++) {
            if (min_d[v[cur][i].first] > cost + v[cur][i].second) {
                min_d[v[cur][i].first] = cost + v[cur][i].second;
                pq.push({ cost + v[cur][i].second,v[cur][i].first });
            }
        }
    }
    return 0;
}

int start() {
    int n, m, t;
    cin >> n >> m >> t;
    int  g, h;
    cin >> s >> g >> h;
    for (int i = 1; i <= n; i++) {
        v[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if ((a == g && b == h) || (a == h && b == g)) {
            v[a].push_back({ b,2 * d - 1});
            v[b].push_back({ a,2 * d - 1 });
        }
        else {
            v[a].push_back({b, 2 * d});
            v[b].push_back({a, 2 * d});
        }
    }
    vector<int> end;
    for (int i = 0; i < t; i++) {
        int e;
        cin >> e;
        end.push_back(e);
    }
    fill_n(min_d, 50000, 999999998);
    dijkstra();
    for (int i = 0; i < end.size(); i++) {
        if (min_d[end[i]] % 2 == 1) {
            answer.push_back(end[i]);
        }
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    answer.clear();
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        start();
    }
    return 0;
}