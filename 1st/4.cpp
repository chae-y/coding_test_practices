#include<iostream>
using namespace std;

int main() {
	char data[100];
	int len;
	fgets(data, 100, stdin);//사용자로부터 받아오기

	len = strlen(data);

	for (int i = 0; i < len; i++) {
		if (data[i] >= 'a' && data[i] <= 'z') {
			data[i] = data[i] - 'a' + 'A';
		}
	}

	cout << data;
	return 0;
}