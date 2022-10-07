#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int hang[11], n = 8;
int a[10][10] = { 0 };
int t = 1;
void print()
{
	printf("No. %d\n", t++);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
}
bool judge(int num)
{
	for (int i = 1; i < num; i++)
		if (hang[num] == hang[i] || abs(hang[i] - hang[num]) == num - i)
			//判断列和对角线
			return 0;
	return 1;
}

void dfs(int num)
{
	if (num >= 9) {
		print();
	}
	for (int i = 1; i <= 8; i++)
	{
		hang[num] = i;
		if (a[num][i] != 1 && judge(num))
		{
			a[num][i] = 1;
			dfs(num + 1);
			a[num][i] = 0;
		}

	}

}

int main()
{
	//freopen("1.txt", "w", stdout);
	dfs(1);
	return 0;
}


