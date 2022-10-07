#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 
#include <iostream>
using namespace std;
#define N 512
int(*matrix1)[N];
int(*flag)[N];
int* matrix2;
int* ans;
LARGE_INTEGER start1;
LARGE_INTEGER end1;
LARGE_INTEGER freq1;
void RowFirst() {
 for (int i = 0; i < N; i++) {
  ans[i] = 0;
  for (int k = 0; k < N; k++) {
   ans[i] = ans[i] + matrix1[i][k] * matrix2[k];
  }
 }
}
void ColFirst() {
 for (int i = 0; i < N; i++) {
  for (int j = 0; j < N; j++) {
   flag[i][j] = matrix1[j][i] * matrix2[i];
  }
 }
 for(int i=0;i<N;i++)
  for (int j = 0; j < N; j++) {
   ans[i] += flag[i][j];
  }
}
int main() {
 matrix1 = new int[N][N];
 matrix2 = new int[N];
 ans = new int[N];
 flag = new int[N][N];
 srand(time(NULL));
 for (int rx = 0; rx < N; rx++) {
  for (int lx = 0; lx < N; lx++) {
   matrix1[rx][lx] = rand() % 1000;
  }
 }
 for (int i = 0; i < N; i++) {
  matrix2[i] = rand() % 1000;
 }
 QueryPerformanceFrequency(&freq1);
 QueryPerformanceCounter(&start1);
 RowFirst();
 QueryPerformanceCounter(&end1);
 double dTimeTake = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart*1000.0;
 cout << dTimeTake << endl;
 QueryPerformanceFrequency(&freq1);
 QueryPerformanceCounter(&start1);
 ColFirst();
 QueryPerformanceCounter(&end1);
 double dTimeTake1 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart * 1000.0;
 cout << dTimeTake1;
 delete[]matrix1;
 delete[]matrix2;
 delete[]ans;
 delete[] flag;
 return 0;
}