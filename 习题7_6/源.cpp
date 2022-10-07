#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, time[50], sum = 0, temp = 0;
	cout << "the number of customers: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> time[i];
	sort(time, time + n);
	for (int i = 0; i < n; i++) {
		temp += time[i];
		sum += temp;
	}
	cout << "the sum of min_wait_time: " << sum;
}