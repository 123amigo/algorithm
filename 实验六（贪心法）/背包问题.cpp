#include<iostream>
using namespace std;
float z[100];
void sort(int w[], int v[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		z[i] = (float)v[i] / w[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (z[j] < z[j + 1]) {
				float temp = z[j];
				z[j] = z[j + 1];
				z[j + 1] = temp;
				int temp1 = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp1;
				int temp2 = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp2;
			}
		}
	}
}
void KnapSack(int w[], int v[], int n, float x[], int carryMax) {
	int i = 0;
	sort(w, v, n);
	for (i = 0; w[i] < carryMax; i++) {
		x[i] = 1;
		carryMax -= w[i];
	}
	if (i <= n - 1)
		x[i] = (float)carryMax / w[i];
}
int main() {
	int w[100], v[100], n, carryMax;
	float x[100] = { 0 };
	float maxvalue = 0;
	cout << "��Ʒ������";
	cin >> n;
	cout << "��Ʒ������";
	for (int i = 0; i < n; i++)
		cin >> w[i];
	cout << "��Ʒ��ֵ��";
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << "����������";
	cin >> carryMax;
	KnapSack(w, v, n, x, carryMax);
	for (int i = 0; i < n; i++) {
		if (x[i] == 1) {
			cout << "����Ϊ" << w[i] << "��ֵΪ" << v[i] << "����Ʒȫ������" << endl;
			maxvalue += v[i];
		}
		else if (x[i] == 0) {
			cout << "����Ϊ" << w[i] << "��ֵΪ" << v[i] << "����Ʒ������" << endl;
		}
		else {
			cout << "����Ϊ" << w[i] << "��ֵΪ" << v[i] << "����Ʒ����" << x[i] << endl;
			maxvalue += v[i] * x[i];
		}
	}
	cout << "maxvalue = " << maxvalue << endl;
	return 0;
}