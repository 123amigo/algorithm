#include<iostream>
using namespace std;
int main() {
	int r[100], tag[300];
	int i, j, n, flag = 0;
	memset(tag, 0, sizeof(tag));
	cout << "元素个数为：";
	cin >> n;
	cout << "元素分别为：";
	for (i = 0; i < n; i++)
		cin >> r[i];
	for (i = 0; i < n; i++) {
		if (tag[r[i]] == 0) {
			tag[r[i]] = 1;

		}
		else
			for (j = i; j <= n - 1 - flag; j++) {
				r[j] = r[j + 1];
				flag++;
			}
	}
	cout << "删除重复元素后：";
	for (i = 0; i < n - flag; i++)
		cout << r[i] << ' ';
}