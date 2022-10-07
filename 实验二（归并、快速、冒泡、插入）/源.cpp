#include <iostream>
#include <windows.h>
using namespace std;
#define n 1000
LARGE_INTEGER start1;
LARGE_INTEGER end1;
LARGE_INTEGER freq1;
void Merge(int r[], int r1[], int s, int m, int t) {
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t) {
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}
	while (i <= m)
		r1[k++] = r[i++];
	while (j <= t)
		r1[k++] = r[j++];
}
void MergeSort(int r[], int s, int t) {
	int m;
	int  r1[n];
	if (s == t) {
		delete[]r1;
		return;
	}
	else {
		m = (s + t) / 2;
		MergeSort(r, s, m);
		MergeSort(r, m + 1, t);
		Merge(r, r1, s, m, t);
		for (int i = s; i <= t; i++)
			r[i] = r1[i];
	}
}
void creat1(int r[]) {
	int d, b, c, m, i;
	cin >> b;
	cin >> c;
	cin >> m;
	cin >> d;
	r[0] = d;
	for (i = 1; i < n; i++) {
		r[i] = (b * r[i - 1] + c) % m;
	}


}
void guibing() {
	int* r = new int[n];
	creat1(r);
	MergeSort(r, 0, n - 1);
	delete[]r;

}

int Partition(int r[], int first, int end) {
	int i = first, j = end;
	while (i < j) {
		while (i < j && r[i] <= r[j])
			j--;
		if (i < j) {
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
		}
		while (i < j && r[i] <= r[j])
			i++;
		if (i < j) {
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			j--;
		}
	}
	return i;
}
void QuickSort(int r[], int first, int end) {
	int pivot;
	if (first < end) {
		pivot = Partition(r, first, end);
		QuickSort(r, first, pivot - 1);
		QuickSort(r, pivot + 1, end);
	}
}
void kuaisu() {
	int* r = new int[n];
	creat1(r);
	QuickSort(r, 0, n - 1);
	delete[]r;
}
void maopao() {
	int* r = new int[n];
	int i, j, tag = 0, flag = 1;
	creat1(r);
	for (i = 0; i < n; i++) {
		flag = 1;
		for (j = 0; j < n - i - 1; j++) {
			if (r[j] > r[j + 1]) {
				tag = r[j + 1];
				r[j + 1] = r[j];
				r[j] = tag;
				flag = 0;
			}
		}
		if (flag)
			break;
	}
	delete[]r;
}
void charu() {
	int* a = new int[n];
	int i, j, tag;
	creat1(a);
	for (i = 1; i < n; i++) {
		tag = a[i];
		for (j = i; j > 0; j--) {
			if (tag < a[j - 1]) {
				a[j] = a[j - 1];
			}
			else
				break;
		}
		a[j] = tag;
	}
	delete[]a;
}
int main() {
	for (int i = 0; i < 100; i++) {
		QueryPerformanceFrequency(&freq1);
		QueryPerformanceCounter(&start1);
		kuaisu();
		QueryPerformanceCounter(&end1);
		double duration1 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart;
		cout << duration1 << endl;
	}
	return 0;
}