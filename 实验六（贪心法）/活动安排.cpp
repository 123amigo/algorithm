#include <iostream>
using namespace std;
void sort(int s[], int f[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (f[j] > f[j + 1]) {
				int temp1 = f[j];
				f[j] = f[j + 1];
				f[j + 1] = temp1;
				int temp2 = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp2;
			}
		}
	}
}
int ActiveManage(int s[], int f[], int B[], int n) {
	int i, j;
	B[0] = 1;
	j = 0;
	int count;
	count = 1;
	sort(s, f, n);
	for (i = 1; i < n; i++) {
		if (s[i] >= f[j]) {
			B[i] = 1;
			j = i;
			count++;
		}
		else
			B[i] = 0;
	}
	return count;
}
int main() {
	int s[100], f[100], B[100] = { 0 }, count = 0, n;
	cout << "�ȴ����Ż������";
	cin >> n;
	cout << "���ʼʱ�䣺";
	for (int i = 0; i < n; i++)
		cin >> s[i];
	cout << "�����ʱ�䣺";
	for (int i = 0; i < n; i++)
		cin >> f[i];
	count = ActiveManage(s, f, B, n);
	for (int i = 0; i < n; i++) {
		if (B[i] == 1) {
			cout << "ѡ��ʼʱ��Ϊ��" << s[i] << ",����ʱ��Ϊ��" << f[i] << "�Ļ" << endl;
		}
	}
	cout << "��ѡ����ܻ����Ϊ��" << count << endl;
}
