// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, int K) {
    // ���⿡ �ڵ带 �ۼ����ּ���.
    int answer = 10000;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - K + 1; i++) {
        int temp = arr[i + K - 1] - arr[i];
        answer = min(answer, temp);
    }
    return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
    vector<int> arr = { 9, 11, 9, 6, 4, 19 };
    int K = 4;
    int ret = solution(arr, K);

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "solution �Լ��� ��ȯ ���� " << ret << " �Դϴ�." << endl;
}