#include<iostream>
#include<queue>;

using namespace std;

struct Que {
	int x; int time;
};

bool is_prime_number(int n) {
	for (int i = 2; i * i < 10000; i++) {
		if (n % i == 0)	return false;
	}
	return true;
}

int solution(int s, int e) {
	queue<Que> q;
	bool check[10000] = { false };
	q.push({ s,0 });
	check[s] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.x == e) {
			cout << cur.time << endl;
			break;
		}
		int current = cur.x;
		int arr[4], copy[4];
		//숫자 자리수대로 나누기
		for (int i = 0; i < 4 ; i++) {
			arr[i] = current % 10;
			copy[i] = arr[i];
			current = current / 10;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i] = j;

				int next = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];
				if (check[next] || next == cur.x || arr[3] == 0) continue;
				if (is_prime_number(next)) {
					q.push({ next,cur.time+1});
					check[next] = true;
				}
			}
			arr[i] = copy[i];
		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		solution(start, end);
	}
	return 0;
}