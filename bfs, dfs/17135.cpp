#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct enemy {
    int x, y, dis[3];
};

vector<enemy> enemies;
int dead[225];
int N, M, D;

int enemy_c;
int result = 500;

int start(vector<int> archer_pos) {
    int e_cnt = enemy_c;
    int e_catch = 0;
    int round = 0;
    int target_idx[3];
    for (int i = 0; i < enemy_c; i++) {
        for (int j = 0; j < 3; j++)
            enemies[i].dis[j] = N - enemies[i].x + abs(enemies[i].y - archer_pos[j]);
    }
    while (e_cnt > 0) {
        for (int i = 0; i < 3; i++) target_idx[i] = -1;
        for (int i = 0; i < enemy_c; i++) {
            //살아있는지 체크
            if (!dead[i] && enemies[i].x + round >= N) {
                dead[i] = 1;
                if (--e_cnt) break;
            }
            if (dead[i]) continue;
            //적은거 찾기
            for (int j = 0; j < 3; j++) {
                int dis = enemies[i].dis[j] - round;
                if (dis <= D) {
                    if (target_idx[j] == -1) target_idx[j] = i;
                    else {
                        if (enemies[target_idx[j]].dis[j] - round > dis) {
                            target_idx[j] = i;
                        }
                        else if (enemies[target_idx[j]].dis[j] - round == dis) {
                            if (enemies[target_idx[j]].y > enemies[i].y)   target_idx[j] = i;
                        }
                    }
                }
            }
        }
        //제거
        for (int i = 0; i < 3; i++) {
            if (target_idx[i] != -1 && !dead[target_idx[i]]) {
                dead[target_idx[i]] = 1;
                e_catch++;
                e_cnt--;
            }
        }
        round++;
    }
    if (result > e_catch)  result = e_catch;
    return 0;
}

void archer_position(int idx, int cnt, vector<int> pos)
{
    if (pos.size() == 3)
    {
        start(pos);

        // 죽음 초기화
        fill_n(dead, 225, 0);

        return;
    }
    if (idx == M) return;
    // 배치 안한다
    archer_position(idx + 1, cnt, pos);
    // 배치 한다
    pos.push_back(idx);
    archer_position(idx + 1, cnt, pos);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            if (temp == 1)   enemies.push_back({ i,j });
        }
    }
    enemy_c = enemies.size();
    archer_position(0, 3, {});
    cout << result;
    return 0;
}