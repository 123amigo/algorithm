#include<iostream>
using namespace std;
int getMax(int a[], int l, int r) {
	int ans, u, v;
	int m = (l + r) / 2;
	if (r - l == 1)
		return a[l];
	else {
		u = getMax(a, l, m);
		v = getMax(a, m, r);
		ans = max(u, v);
	}
	return ans;
}
int main() {
	int a[10] = { 1,2,4,6,78,4,32,4,5,7 };
	cout << getMax(a, 0, 10);
	return 0;
}