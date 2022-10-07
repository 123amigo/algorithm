#include <iostream> 
#include <math.h>
#include<time.h>
using namespace std;

int force(int m, int n) {
	int i, ans = 1;
	for (i = 2; i <= n; i++) {
		if (m % i == 0 && n % i == 0)
			ans = i;
	}
	return ans;
}
int sub(int m, int n) {
	int r;
	r = m - n;
	while (r != 0) {
		m = n;
		n = r;
		r = abs(m - n);
	}
	return n;
}
int chufa(int m, int n) {
	int r;
	r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}
void creat1() {
	int d, b, c, m, n, i;
	int* arr;
	cout << "���������������";
	cin >> n;
	arr = new int[n];
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "m = ";
	cin >> m;
	cout << "�������d = ";
	cin >> d;
	arr[0] = d;
	for (i = 1; i < n; i++) {
		arr[i] = (b * arr[i - 1] + c) % m;
	}
	cout << "�������Ϊ��";
	for (i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	delete[]arr;

}
void Random() {
	int ans;
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	srand((unsigned)time(NULL));
	ans = rand() % (b - a) + a;
	cout << "�����Ϊ��" << ans << endl;
}
int main() {
	int ans, m, n;
	cout << "input two integers: ";
	cin >> m >> n;
	ans = force(m, n);
	cout << "�������� " << ans << endl;
	ans = sub(m, n);
	cout << "ŷ����ü����� " << ans << endl;
	ans = chufa(m, n);
	cout << "ŷ����ó����� " << ans << endl;
	creat1();
	Random();
	return 0;
}