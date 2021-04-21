#include <iostream>
#include <vector>

using namespace std;

vector<char> v[200];

int main() {
    int n;
    cin >> n;
    int k = 4 * n - 3;
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0)
            v[0].push_back('*');
        else
            v[0].push_back(' ');
    }//중간
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < k; j++) {
            if (j % 2 == 0) {
                v[2 * i - 1].push_back('*'); v[2 * i].push_back('*');
            }
            else {
                v[2 * i - 1].push_back(' '); v[2 * i].push_back(' ');
            }
        }
        int j = 0;
        while (j <= 2*i-1) {
            v[2 * i - 1][k / 2 - j] = ' ';
            v[2 * i - 1][k / 2 + j] = ' ';
            v[2 * i][k / 2 - j] = '*';
            v[2 * i][k / 2 + j] = '*';
            j++;
        };
    }
    for (int i = 2 * n - 2; i > 0; i--) {
        for (int j = 0; j < k; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < k; i++) {
        cout<<v[0][i];
    }
    cout << endl;
    for (int i = 1; i <= 2 * n - 2; i++) {
        for (int j = 0; j < k; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}