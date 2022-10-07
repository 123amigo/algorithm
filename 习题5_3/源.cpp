#include<iostream>
#include<stdio.h>
using namespace std;
//折半进行范围查找函数：
void ZheBan(int min, int max, int r[], int low, int high)
{
    int mid;
    mid = (low + high) / 2;
    if (r[mid] < min)
        ZheBan(min, max, r, mid, high);
    else if (r[mid] > max)
        ZheBan(min, max, r, low, mid);
    //if(r[mid]>=a && r[mid]<=b)
    else
    {
        for (int i = mid; r[i] >= min && i >= low; i--)
            printf("%d ", r[i]);
        for (int j = mid + 1; r[j] <= max && j <= high; j++)
            printf("%d ", r[j]);
    }
}
int main()
{
    int r[5], min, max;
    printf("请输入数组元素：");
    for (int i = 0; i < 5; i++)
        scanf_s("%d", &r[i]);
    printf("请输入查找范围最小值min和最大值max：");
    scanf_s("%d%d", &min, &max);
    ZheBan(min, max, r, 0, 4);
    printf("\n");
    return 0;
}
