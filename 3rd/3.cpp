#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n = 100;
	int *arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i <n; i++) {
		arr[i] = i;
	}

	cout << "exitst: " << binary_search(arr, arr + n, 70) << endl;
	return 0;
}