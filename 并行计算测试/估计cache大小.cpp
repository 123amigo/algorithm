#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <windows.h>
LARGE_INTEGER start1;
LARGE_INTEGER end1;
LARGE_INTEGER freq1;
using namespace std;
#define READ_TIMES 99999999
#define TEST_RANGE 24

int main()
{
    int i;
    int* block_size = new int[TEST_RANGE];
    for (i = 0; i < TEST_RANGE; ++i)
        block_size[i] = pow(2, i);
    srand(time(NULL));
    for (i = 0; i < TEST_RANGE; ++i)
    {
        int size = block_size[i];
        int* block = new int[size];
        memset(block, 0, sizeof(int) * size);
        int j, temp = 0;
        QueryPerformanceFrequency(&freq1);
        QueryPerformanceCounter(&start1);
        for (j = 0; j < READ_TIMES; ++j)
            temp += block[rand() % size];
        QueryPerformanceCounter(&end1);
        double dTimeTake = (double)(end1.QuadPart - start1.QuadPart) / (double)freq1.QuadPart;

        printf("At size: %ldB, we need %lf sec\n", size * sizeof(int), (double)dTimeTake);
        delete[]block;
    }
        delete[]block_size;
    
    return 0;
}