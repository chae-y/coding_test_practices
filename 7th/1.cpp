#include<iostream>

using namespace std;

int IDT[1 << 18], n, q, base;

void update(int a, int b) {
	IDT[a] = b;
	a /= 2;
	while (a) {
		IDT[a] = IDT[2 * a] + IDT[2 * a + 1];
		a /= 2;
	}
}

int lg_sum(int a, int b) {
	int sum = 0;
	while (a < b) {
		if (a % 2 == 1)	sum += IDT[a], a++;
		if (b % 2 == 0)	sum += IDT[b], b--;
		a /= 2, b /= 2;
	}
	if (a == b)	sum += IDT[a];
	return sum;
}

int main() {
	cin >> n;
	for (base = 1; base < n; base *= 2);
	for (int i = base; i < n + base; i++) {
		cin >> IDT[i];
	}
	for (int i = base - 1; i > 0; i--) {
		IDT[i] = IDT[2 * i] + IDT[2 * 1 + 1];
	}
	cin >> q;
	while (q--){
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 1){
			cout << lg_sum(base + a - 1, base + b - 1) << endl;
		}
		else{
			update(base + a - 1, b);
		}
	}
	return 0;
}