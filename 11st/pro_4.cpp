// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> garden) {
    // ���⿡ �ڵ带 �ۼ����ּ���.
    int answer = 0;
    vector<pair<int, int>> v;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };

    for (int i = 0; i < garden.size(); i++) {
        for (int j = 0; j < garden.size(); j++) {
            if (garden[i][j]) v.push_back({ i,j });
        }
    }
    while (true) {
        int s = v.size();
        if (s == garden.size() * garden.size()) break;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = v[i].first + dx[j];
                int ny = v[i].second + dy[j];
                if (nx < 0 || nx >= garden.size()) continue;
                if (ny < 0 || ny >= garden.size()) continue;
                if (!garden[nx][ny]) {
                    garden[nx][ny] = 1;
                    v.push_back({ nx,ny });
                }
            }
        }
        answer++;
    }

    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    vector<vector<int>> garden1 = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    int ret1 = solution(garden1);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "solution �Լ��� ��ȯ ���� " << ret1 << " �Դϴ�." << endl;

    vector<vector<int>> garden2 = { {1, 1}, {1, 1} };
    int ret2 = solution(garden2);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "solution �Լ��� ��ȯ ���� " << ret2 << " �Դϴ�." << endl;
}