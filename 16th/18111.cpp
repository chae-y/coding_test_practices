#include<iostream>
using namespace std;

int N, M, B;
int map[500][500];
int result = 999999999;
int height = 0;

int start() {
	for(int k=0; k<=256; k++){
		int time = 0;
		int block = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int temp = k - map[i][j];
				if (temp < 0) {
					time -= (temp * 2);
					block -= temp;
				}
				else {
					time += temp;
					block -= temp;
				}
			}
		}
		if (time <= result && block >=0 ) {
			height = k;
			result = time;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	start();

	cout << result<<" "<<height;

	return 0;
}