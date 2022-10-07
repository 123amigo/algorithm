#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <queue>
LARGE_INTEGER start1;
LARGE_INTEGER end1;
LARGE_INTEGER freq1;
using namespace std;
int NUM;
#define MAXWEIGHT 100 
/*
2 2 6 5 4
6 5 4 3 6*/
void power(int* w0, int* v0) {
	int* w = w0;
	int* v = v0;
	int upper = (int)pow(NUM, 2);
	int maxvalue = 0, sumvalue = 0, sumweight = 0;
	int subset[100], temp[100];
	int i, j, k, s;
	for (i = 0; i < upper; i++) {
		s = i;
		sumvalue = 0;
		sumweight = 0;
		memset(subset, 0, NUM * sizeof(int));
		for (j = 0; s != 0; j++) {
			subset[j] = s % 2;
			s = (unsigned int)s / 2;
		}
		for (k = 0; k < NUM; k++) {
			if (subset[k] == 1) {
				sumweight += w[k + 1];
				if (sumweight <= MAXWEIGHT)
					sumvalue += v[k + 1];
				else
					break;
			}
		}
		if (sumvalue > maxvalue && k == NUM) {
			maxvalue = sumvalue;
			memcpy(temp, subset, NUM * sizeof(int));

		}
	}
	cout << "������: " << endl;
	cout << "item: ";
	for (i = 0; i < NUM; i++) {
		if (temp[i] == 1)
			cout << i + 1 << " ";
	}
	cout << endl;
	cout << "maxvalue = " << maxvalue << endl;
}
int dp[105][MAXWEIGHT + 1] = { {0} };
int ans[105];
void dynamic(int* w, int* v) {
	int bagV = MAXWEIGHT;
	for (int i = 1; i <= NUM; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}

	}

}
void findwhat(int i, int j, int* w, int* v) {
	if (i >= 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			ans[i] = 0;
			findwhat(i - 1, j, w, v);
		}
		else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
			ans[i] = 1;
			findwhat(i - 1, j - w[i], w, v);
		}
	}
}
void print() {
	cout << "��̬�滮��: " << endl;
	cout << "item: ";
	for (int k = 1; k <= NUM; k++) {
		if (ans[k] == 1) {
			cout << k << " ";
		}
	}
	cout << endl;
	cout << "maxvalue = " << dp[NUM][MAXWEIGHT] << endl;
}

void dongtai(int* w0, int* v0) {
	int* w = w0;
	int* v = v0;
	dynamic(w, v);
	findwhat(NUM, MAXWEIGHT, w, v);
	print();
}

typedef struct QNode {
	int value;
	int weight;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}Queue;

int x[100] = { 0 };
int x0[100] = { 0 };
int maxvalue = 0;

void knapsack(int k, int r, int cv, int rv, int rw, int* w, int* v) {
	if (k < NUM) {
		if (r >= 0 && cv > maxvalue) {
			maxvalue = cv;
			for (int i = 1; i <= k; i++)
				x0[i] = x[i];
			for (int i = k + 1; i <= NUM; i++)
				x0[i] = 0;
		}
		if (rw <= r) {
			if (rv + cv > maxvalue) {
				maxvalue = cv + rv;
				for (int i = 1; i <= k; i++)
					x0[i] = x[i];
				for (int i = k + 1; i <= NUM; i++)
					x0[i] = 1;
			}
		}
		else {
			if (r > 0 && cv + rv > maxvalue) {
				rv = rv - v[k + 1];
				rw = rw - w[k + 1];
				x[k + 1] = 0;
				knapsack(k + 1, r, cv, rv, rw, w, v);
				x[k + 1] = 1;
				knapsack(k + 1, r - w[k + 1], cv + v[k + 1], rv, rw, w, v);
			}
		}
	}

}
void huisu(int* w0, int* v0) {
	int* w = w0;
	int* v = v0;
	int rv = 0, rw = 0;
	for (int i = 1; i <= NUM; i++) {
		rv = rv + v[i];
		rw = rw + w[i];
	}
	knapsack(0, MAXWEIGHT, 0, rv, rw, w, v);
	cout << "���ݷ�: " << endl;
	cout << "item: ";
	for (int i = 1; i <= NUM; i++) {
		if (x0[i] == 1)
			cout << i << ' ';
	}
	cout << endl;
	cout << "maxvalue = " << maxvalue << endl;
}


int bestv = 0;
int bestx[105];
int total = 1;
//��ռ��еĽڵ����ۼƣ�ȫ�ֱ��� 
struct nodetype        //�����еĽ������
{
	int no;            //����ţ���1��ʼ 
	int i;            //��ǰ����������ռ��еĲ�� 
	int w;            //��ǰ���������� 
	int v;            //��ǰ�����ܼ�ֵ 
	int x[100];    //��ǰ�������Ľ����� 
	double ub;        //�Ͻ� 
};


void bound(nodetype& e, int* w0, int* v0)        //�����֧���e���Ͻ� 
{
	int* w = w0;
	int* v = v0;
	int c = MAXWEIGHT;
	int i = e.i + 1;        //���ǽ��e��������Ʒ
	int sumw = e.w;
	double sumv = e.v;
	while ((sumw + w[i] <= c) && i <= NUM)
	{
		sumw += w[i];
		sumv += v[i];
		i++;
	}
	if (i <= NUM)            //������Ʒֻ�ܲ���װ�� 
		e.ub = sumv + (c = c - sumw) * v[i] / w[i];
	else e.ub = sumv;
}

void enqueue(nodetype e, queue<nodetype>& qu)
//���e����qu 
{
	if (e.i == NUM)                //����Ҷ�ӽڵ㣬������չ��Ӧһ���� 
	{
		if (e.v > bestv)        //�ҵ������ֵ�Ľ� 
		{
			bestv = e.v;
			for (int j = 1; j <= NUM; j++)
				bestx[j] = e.x[j];
		}
	}
	else qu.push(e);        //��Ҷ�ӽ�����
}

void bfs(int* w0, int* v0)
{
	int* w = w0;
	int* v = v0;
	int j;
	nodetype e, e1, e2;
	queue<nodetype> qu;

	e.i = 0;
	e.w = 0;
	e.v = 0;
	e.no = total++;

	for (j = 1; j <= NUM; j++)
		e.x[j] = 0;
	bound(e, w0, v0);
	qu.push(e);

	while (!qu.empty())
	{
		e = qu.front(); qu.pop();    //���ӽ��e 
		if (e.w + w[e.i + 1] <= MAXWEIGHT)        //��֦��������ӽ�� 
		{
			e1.no = total++;        //�������ӽ�� 
			e1.i = e.i + 1;
			e1.w = e.w + w[e1.i];
			e1.v = e.v + v[e1.i];
			for (j = 1; j <= NUM; j++)
				e1.x[j] = e.x[j];
			e1.x[e1.i] = 1;
			bound(e1, w0, v0);        //�����ӵ��Ͻ� 
			enqueue(e1, qu);    //���ӽ����� 
		}
		e2.no = total++;
		e2.i = e.i + 1;
		e2.w = e.w;
		e2.v = e.v;
		for (j = 1; j <= NUM; j++)
			e2.x[j] = e.x[j];
		e2.x[e2.i] = 0;
		bound(e2, w0, v0);
		if (e2.ub > bestv)        //���Һ��ӽ����У�����ӣ����򱻼�֦ 
			enqueue(e2, qu);
	}
}

void output()
{
	cout << "��֧�޽編��" << endl;
	cout << "item: ";
	for (int i = 1; i <= NUM; i++)
		if(bestx[i]==1)
		cout << i<< " ";
	cout << endl;
	cout << "maxvalue = " << bestv << endl;
}

int main() {
	int i;
	int w0[105], v0[105];
	cout << "the number of items: ";
	cin >> NUM;
	/*printf("input the weights:");
	for (i = 1; i <= NUM; i++)
		scanf_s("%d", &v0[i]);*/
	for (i = 1; i <= NUM; i++) {
		srand((unsigned)time(NULL));
		w0[i] = rand() % (60 - 5) + 5;
	}
	/*printf("input the values:");
	for (i = 1; i <= NUM; i++)
		scanf_s("%d", &v0[i]);*/
	for (i = 1; i <= NUM; i++) {
		srand((unsigned)time(NULL));
		v0[i] = rand() % (100 - 20) + 20;
	}
	QueryPerformanceFrequency(&freq1);
	QueryPerformanceCounter(&start1);
	power(w0, v0);
	QueryPerformanceCounter(&end1);
	double duration1 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart;
	cout <<"time: "<< duration1 << endl;
	QueryPerformanceFrequency(&freq1);
	QueryPerformanceCounter(&start1);
	dongtai(w0, v0);
	QueryPerformanceCounter(&end1);
	double duration2 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart;
	cout << "time: " << duration2 << endl;
	QueryPerformanceFrequency(&freq1);
	QueryPerformanceCounter(&start1);
	huisu(w0, v0);
	QueryPerformanceCounter(&end1);
	double duration3 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart;
	cout << "time: " << duration3 << endl;
	QueryPerformanceFrequency(&freq1);
	QueryPerformanceCounter(&start1);
	bfs(w0, v0);
	output();
	QueryPerformanceCounter(&end1);
	double duration4 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart;
	cout << "time: " << duration4 << endl;
	
	return 0;
}




