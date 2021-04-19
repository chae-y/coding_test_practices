#include <iostream>

using namespace std;

int recursive(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2) return 1 - recursive(n / 2);
    else return recursive(n / 2);
}

int main() {
    long long x;
    cin >> x;
    cout<<recursive(x-1);
    return 0;
}