#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
struct Point {
	double x;
	double y;
};
double distance(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int partition(Point a[], int begin, int end) {
	Point key = a[end];
	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (a[j].x <= key.x) {
			i++;
			Point temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	i++;
	a[end] = a[i];
	a[i] = key;
	return i;
}
void quiksort(Point a[], int begin, int end) {
	if (begin < end) {
		int middle = partition(a, begin, end);
		quiksort(a, begin, middle - 1);
		quiksort(a, middle + 1, end);
	}
}
double closest(Point* points, int n, Point& a, Point& b) {
	if (n == 2) {
		a = points[0];
		b = points[1];
		return distance(a, b);
	}
	else if (n < 2) {
		return 999999;
	}
	else {
		int n1 = n / 2;
		int n2 = n - n1;
		int i, j;
		double d1, d2, mid, dis;
		Point* points1 = new Point[n1];
		Point* points2 = new Point[n2];
		Point a1, a2, b1, b2;
		quiksort(points, 0, n - 1);
		mid = points[n1].x;
		for (i = 0; i < n1; i++)
			points1[i] = points[i];
		for (i = 0; i < n2; i++)
			points2[i] = points[i + n1];
		d1 = closest(points1, n1, a1, b1);
		d2 = closest(points2, n2, a2, b2);
		if (d1 <= d2) {
			a = a1;
			b = b1;
			dis = distance(a, b);
		}
		else {
			a = a2;
			b = b2;
			dis = distance(a, b);
		}
		Point* points3 = new Point[n];
		int k = -1;
		for (i = 0; i < n; i++) {
			if (abs(points[i].x - mid) <= dis)
				points[++k] = points[i];
		}
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < k; j++) {
				if (distance(points3[i], points3[j]) < dis) {
					a = points[i];
					b = points[j];
					dis = distance(a, b);
				}
			}
		}
		delete[] points1;
		delete[] points2;
		delete[] points3;
		return dis;
	}
}
int main() {
	Point points[7] = { {1.0,2.0},{1.1,6.2},{5.0,7.0},{15.0,12.5},{2.6,2.5},{5.9,4.6},{9.1,15.8} };
	for (int i = 0; i < 7; i++) {
		printf("(%.2f,%.2f)\n", points[i].x, points[i].y);
	}
	Point a, b;
	double dis = closest(points, 7, a, b);
	printf("¾àÀë%.2f£¬µãa£¨%.2f£¬%.2f£©£¬µãb£¨%.2f£¬%.2f£©", dis, a.x, a.y, b.x, b.y);
}
