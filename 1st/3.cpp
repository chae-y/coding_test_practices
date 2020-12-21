#include<iostream>
using namespace std;

int sum(int i, int j) {
	return i + j;
}

int main(int argc, char* args[]) {
	cout << sum(atoi(args[1]), atoi(args[2]));
}//atoi-> char를 int로 그리고 args[0]은 주소다