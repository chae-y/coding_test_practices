// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> garden) {
    // 여기에 코드를 작성해주세요.
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

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<vector<int>> garden1 = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    int ret1 = solution(garden1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    vector<vector<int>> garden2 = { {1, 1}, {1, 1} };
    int ret2 = solution(garden2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}