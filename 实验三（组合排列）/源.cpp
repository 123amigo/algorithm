#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
#define MAXIN 10
int a[MAXIN] = { 0 };
int counts = 0;
void comb(int n, int m)
{
	if (m <= 0)
	{
		for (int j = 1; j <= counts; j++)
			printf("%d ", a[j]);
		printf("\n");


		return;
	}
	for (int i = n; i >= m; i--)
	{
		a[m] = i;
		comb(i - 1, m - 1);
	}
}
void zuhe(int n, int m) {
	int* flag = new int[n];
	int i = 0, j;
	for (i = 0; i < n; i++) {
		if (i < m)
			flag[i] = 1;
		else
			flag[i] = 0;
	}
	for (i = 0; i < n; i++) {
		if (flag[i] == 1) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	i = 0;
	while (i < n - 1) {
		int temp, x = 0, y = 0;
		if (flag[i] == 1 && flag[i + 1] == 0) {
			temp = flag[i];
			flag[i] = flag[i + 1];
			flag[i + 1] = temp;
			while (y < i) {
				if (flag[y]) {
					temp = flag[y];
					flag[y] = flag[x];
					flag[x] = temp;
					x++;
				}
				y++;
			}
			for (j = 0; j < n; j++) {
				if (flag[j] == 1)
					cout << j + 1 << " ";
			}
			cout << endl;
			i = (x == 0 ? 0 : x - 1);
		}
		else
			i++;
	}
}
/*蛮力法解决全排列问题*/
void insert(char c1[], char c2[], char c, int i)
//将c 插入c1 并将c1复制到c2
{
	int j;
	for (j = 0; j < i; j++)
		c2[j] = c1[j];
	c2[i] = c;
	for (j = i + 1; j <= strlen(c1) + 1; j++)
		c2[j] = c1[j - 1];
}


void perml(int n)//为生成排列集合元素的个数
{
	int i, j, k, m = 1;


	char** c[2];//采用两个字符序列存储，分别存储i-1和i的全排列
	c[1] = new char* [1];
	c[1][0] = new char[2];
	c[1][0][0] = '1'; c[1][0][1] = 0;


	for (i = 2; i <= n; i++)
	{
		m = m * (i - 1);
		c[i % 2] = new char* [m * i];
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < i; k++)
			{
				c[i % 2][j * i + k] = new char[i + 1];
				insert(c[(i + 1) % 2][j], c[i % 2][j * i + k], char(i + '0'), k);
			}
			delete[] c[(i + 1) % 2][j];
		}
		delete[] c[(i + 1) % 2];
	}
	for (i = 0; i < m * n; i++)
	{
		cout << "第" << i + 1 << "排列：" << c[n % 2][i] << endl;
		delete[] c[n % 2][i];
	}
}

int main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	counts = m;
	zuhe(n, m);
	perml(m);
	return 0;
}
