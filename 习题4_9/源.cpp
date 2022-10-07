#include<iostream>
using namespace std;
void getAns(int a[], int n) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == mid) {
			cout << "找到这个元素，其值为：" << a[mid];
			break;
		}
		else if (a[mid] > mid)
			high = mid - 1;
		else
			low = mid + 1;
	}
}
int main() {
	int a[7] = { 1,2,34,3,7,8,0 };
	getAns(a, 7);
}