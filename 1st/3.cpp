#include<iostream>
using namespace std;

int sum(int i, int j) {
	return i + j;
}

int main(int argc, char* args[]) {
	cout << sum(atoi(args[1]), atoi(args[2]));
}//atoi-> char�� int�� �׸��� args[0]�� �ּҴ�