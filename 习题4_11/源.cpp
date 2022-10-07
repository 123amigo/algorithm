#include <iostream>
using namespace std;
#define n 5
int x = 2;
int getAns(int a[n][n], int rl, int rh, int ll, int lh) {
	int rm = (rl + rh) / 2;
	int lm = (ll + lh) / 2;
	if (rl > rh || ll > lh)
		return 0;
	else if (rl == rh && ll == lh)
		return 0;
	if (a[rm][lm] == x) {
		cout << "存在，其行下标为：" << rm << "其列下标为：" << lm;
		return 1;
	}
	else if (x > a[rm][lm])
		return getAns(a, rm + 1, rh, ll, lh) || getAns(a, rl, rh, ll + 1, lh);
	else
		return getAns(a, rl, rm - 1, ll, lh) || getAns(a, rl, rh, ll, lm - 1);
}
int main() {
	int a[n][n] =
	{
		{ 1, 2, 3, 4, 5},
		{ 6, 7, 8, 9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
	getAns(a, 0, 4, 0, 4);
	return 0;
}