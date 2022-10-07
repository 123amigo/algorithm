#include<iostream>
using namespace std;
int main() {
	int x, y, ans, max = 0, xx, yy;
	for (x = 0; x <= 4; x++)
		for (y = 0; y <= 4; y++) {
			if (x + y <= 4 && x + 3 * y <= 6) {
				ans = 3 * x + 5 * y;
			}
			if (ans > max) {
				xx = x;
				yy = y;
				max = ans;
			}
		}
	cout << "x=" << xx << "," << "y=" << yy << "," << "¼«´óÖµ=" << max;
}