#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 
#include <iostream>
using namespace std;
#define N 24
#define BLOCKSIZE 4
int(*matrix1)[N];
int(*flag)[N];
int (*matrix2)[N];

LARGE_INTEGER start1;
LARGE_INTEGER end1;
LARGE_INTEGER freq1;
 void do_block( int* A, int* B, int* C){

    for (int i = 0; i < BLOCKSIZE; i++){
        for (int j = 0; j < BLOCKSIZE; j++){
            int cij = C[i * N + j];
            for (int k = 0; k < BLOCKSIZE; k++)
                cij += A[i * N + k] * B[k * N + j];
            C[i * N + j] = cij;
        }
    }
}

void dgemm_block( int* A, int* B, int* C){
    for (int sj = 0; sj < N; sj += BLOCKSIZE)
        for (int si = 0; si < N; si += BLOCKSIZE)
            for (int sk = 0; sk < N; sk += BLOCKSIZE)
                do_block( A + si * N + sk, B + sk * N + sj, C + si * N + sj);

}

void juzheng(int* A, int* B, int* C) {
    int sum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i*N+k] * B[k*N+j];
            }
            C[i*N+j] = sum;
        }
    }
}

int main() {
    matrix1 = new int[N][N];
    matrix2 = new int[N][N];
    flag = new int[N][N];
    srand(time(NULL));
    for (int rx = 0; rx < N; rx++) {
        for (int lx = 0; lx < N; lx++) {
            matrix1[rx][lx] = rand() % 1000;
        }
    }
    for (int rx = 0; rx < N; rx++) {
        for (int lx = 0; lx < N; lx++) {
            matrix2[rx][lx] = rand() % 1000;
        }
    }
    QueryPerformanceFrequency(&freq1);
    QueryPerformanceCounter(&start1);
    dgemm_block(matrix1[0],matrix2[0],flag[0]);
    QueryPerformanceCounter(&end1);
    double dTimeTake = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart * 1000.0;
    cout << dTimeTake << endl;
    QueryPerformanceFrequency(&freq1);
    QueryPerformanceCounter(&start1);
    juzheng(matrix1[0], matrix2[0], flag[0]);
    QueryPerformanceCounter(&end1);
    double dTimeTake1 = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart * 1000.0;
    cout << dTimeTake1 << endl;
    delete[]matrix1;
    delete[]matrix2;
    delete[]flag;

    return 0;
}