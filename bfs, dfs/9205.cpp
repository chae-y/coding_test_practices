#include<iostream>

using namespace std;

int t, n;

struct map {
	int x, y;
};

map house, rock, con[100];
int beer, result;
int visited[100];

int solution(int sx, int sy) {
	int distance = abs(rock.x - sx) + abs(rock.y - sy);
	if ((distance + 49) / 50 <= 20) {
		result = 1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int dis_c = abs(con[i].x - sx) + abs(con[i].y - sy);
		if ((dis_c + 49) / 50 <= 20 && visited[i]==0) {
			visited[i] = 1;
			solution(con[i].x, con[i].y);
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> house.x >> house.y;
		for (int j = 0; j < n; j++) {
			cin >> con[j].x >> con[j].y;
		}
		cin >> rock.x >> rock.y;
		result = 0;
		fill_n(visited, 100, 0);
		solution(house.x,house.y);
		if (result == 1)	cout << "happy\n";
		else cout << "sad\n";
	}

	
	return 0;
}