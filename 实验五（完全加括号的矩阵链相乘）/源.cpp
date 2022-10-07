#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 50
#define MAX 0xfffffff
int n;
int p[N];//p���鱣�����ǵ�����������
int s[N][N], dp[N][N];//s�洢�и�λ�ã�dp�洢����ֵ
void MatrixChain() {
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++) {
			s[i][j] = 0;
			dp[i][j] = MAX;
		}
	cout << "������к���" << endl;
	for (int i = 0; i < n + 1; i++) {
		cin >> p[i];
		dp[i][i] = 0;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n; i++) {
			int j = i + l - 1;
			if (j > n)
				break;
			for (int k = i; k < j; k++) {
				int min = dp[i][j];
				int temp = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < min) {
					dp[i][j] = temp;
					min = temp;
					s[i][j] = k;
				}
			}
		}
	}
}
void Traceback(int i, int j) {
	if (i == j)
		return;
	int k = s[i][j];
	Traceback(i, k);
	Traceback(k + 1, j);
	cout << "A[" << i << ":" << k << "]*A[" << k + 1 << ":" << j << "]" << endl;
}
int main() {
	cout << "�������" << endl;
	cin >> n;
	MatrixChain();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << setw(10) << dp[i][j] << " ";
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << setw(5) << s[i][j] << " ";
		cout << endl;
	}
	cout << "���˵����ٴ�����" << dp[1][n] << "�Ρ�" << endl;
	Traceback(1, n);
}
