#include<iostream>

using namespace std;

struct {
	int red, green, blue;
}house[1001],cost[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> house[i].red >> house[i].green >> house[i].blue;
	}
	house[0].blue = house[0].green = house[0].red = 0;
	cost[0].blue = cost[0].green = cost[0].red;
	for (int i = 1; i <= n; i++) {
		cost[i].blue = min(cost[i - 1].green, cost[i - 1].red) + house[i].blue;
		cost[i].green = min(cost[i - 1].blue, cost[i - 1].red) + house[i].green;
		cost[i].red = min(cost[i - 1].green, cost[i - 1].blue) + house[i].red;
	}

	cout << min(cost[n].blue, min(cost[n].green, cost[n].red));

	return 0;
}