#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
void Backtrack(int i);
int n = 0, y = 0, sum = 0;
int a[100] = { 0 };
bool record[100] = { false };
bool found = false;
int main()
{
    cin >> n >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Backtrack(1);
    for (int i = 1; i <= n; i++) {
        if (record[i] == true)
            cout << a[i] << " ";
    }
    if (found == false)
        cout << "No Solution";
}
void Backtrack(int i) {
    if (i > n) {//һ����֧����
        if (sum == y)//�ҵ��⣬��־λ�ı�
            found = true;
        return;
    }
    if (found == false) {
        sum += a[i];
        record[i] = true;
        Backtrack(i + 1);
        if (found == true)
            return;
        sum -= a[i];
        record[i] = false;
        Backtrack(i + 1);
    }
}


