#include <iostream>
using namespace std;
#include <windows.h>
#include <time.h> // For struct timespec, clock_gettime, CLOCK_MONOTONIC
# define NUM 100000000
# define X 1024*1024*1024
LARGE_INTEGER start1;
LARGE_INTEGER end1;
LARGE_INTEGER freq1;

int main() {
    int* a;
    a = new int[NUM];
    for (int i = 0; i < NUM; i++)
        a[i] = 0;
    int flag;
    QueryPerformanceFrequency(&freq1);
    QueryPerformanceCounter(&start1);
    for (int i = 0; i < NUM; i += 16) {
        flag = a[i];
    }
    QueryPerformanceCounter(&end1);
    double dTimeTake = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart ;
    double ans = (double)(4.0 * NUM) / (X * dTimeTake);
    cout << ans;
    delete[]a;
    return 0;
}


