#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v[50000];
int visited[50000] = { 0, };
int min_d[50000];
vector<int> answer;

int dfs(int s, int cnt) {
    min_d[s] = min(min_d[s], cnt);
    for (int i = 0; i < v[s].size(); i++) {
        if (visited[v[s][i].first] == 0) {
            visited[v[s][i].first] = 1;
            dfs(v[s][i].first, cnt + v[s][i].second);
            visited[v[s][i].first] = 0;
        }
    }
    return 0;
}

int start() {
    int n, m, t;
    cin >> n >> m >> t;
    int s, g, h;
    cin >> s >> g >> h;
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if ((a == g && b == h) || (a == h && b == g)) {
            v[a].push_back({ b,2 * d - 1 });
            v[b].push_back({ a,2 * d - 1 });
        }
        else {
            v[a].push_back({ b,2 * d });
            v[b].push_back({ a,2 * d });
        }
    }
    vector<int> end;
    for (int i = 0; i < t; i++) {
        int e;
        cin >> e;
        end.push_back(e);
    }
    fill_n(visited, 50000, 0);
    fill_n(min_d, 50000, 999999998);
    visited[s] = 1;
    dfs(s, 0);
    for (int i = 0; i < end.size(); i++) {
        if(min_d[end[i]]%2==1) answer.push_back(end[i]);
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
}9