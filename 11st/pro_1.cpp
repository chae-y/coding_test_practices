#include <string>
#include <vector>
#include <string>

using namespace std;

int a[3] = { 1,2,4 };
vector<int> v;

string solution(int n) {
    string answer = "";
    int leave;
    while (true) {
        n--;
        if (n < 3) {//³¡
            v.push_back(a[n % 3]);
            break;
        }
        v.push_back(a[n % 3]);
        n = n / 3;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        answer += to_string(v[i]);
    }
    return answer;
}