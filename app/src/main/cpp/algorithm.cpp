//
// Created by aimar on 2018/4/21.
//

#include "algorithm.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

// 直接插入排序是一种最简单的插入排序。
// 插入排序：每一趟将一个待排序的记录，
// 按照其关键字的大小插入到有序队列的合适位置里，知道全部插入完成
void insert_sort(int *arr, int len) {
    int i, j, temp;

    for (i = 1; i < len; i++)
    {
        temp = arr[i];

        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }

        arr[j + 1] = temp;
    }
}

// 从头向尾遍历, 将最大数沉入如果后部
void bubble_sort(int *arr, int size)
{
    int i = 0;
    int j = 0;
    int tmp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// 快速排序, 速度快但不稳定
// 快排是对冒泡排序的一种改进，在快速排序中，元素的比较和移动是从两端向中间进行的，
// 关键码较大的元素一次就能从前面移动到后面，关键码较小的元素一次就能从后面移动到前面，
// 元素移动距离的较远，从而减少了总的比较次数和移动次数
void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int x = arr[left];

        while (i < j)
        {
            while (i < j && arr[j] >= x)//从右到左找到第一个小于x的数
                j--;
            if (i < j)
                arr[i++] = arr[j];

            while (i < j && arr[i] <= x)//从左往右找到第一个大于x的数
                i++;
            if (i < j)
                arr[j--] = arr[i];

        }

        arr[i] = x;//i = j的时候，将x填入中间位置
        quick_sort(arr, left, i - 1);//递归调用
        quick_sort(arr, i + 1, right);
    }
}

// 归并排序
// 速度仅次于快速排序，且稳定排序算法
//将两个有序序列合并为一个有序序列
//合并数组的前半部分和后半部分， 前提就是前后两个子数组分别都已经排好序了
void mergeArray(int a[], int first, int mid, int last) {

    int i, j, m, n;
    i = first, m = mid;
    j = mid+1, n = last;
    int k = 0;

    int len = last - first + 1;
    int *temp = (int*)malloc(sizeof(int)*len);

    while(i<=m && j<=n) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while(i<=m) temp[k++] = a[i++];
    while(j<=n) temp[k++] = a[j++];

    for(i=0; i<k; i++) {
        a[first+i] = temp[i];
    }

    free(temp);

}

//归并排序
void merge_sort(int a[], int start, int end) {
    int mid = (start + end) / 2;
    if(start< end) {
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        mergeArray(a, start, mid, end);
    }
}

// 二分法查找, 使用前需先对数组进行排序
int binary_search(int arr[], int len, int key)
{

    int high, low;
    high = len - 1;//假设数组是从小到大排列的
    low = 0;
    int midle = len / 2;

    while (high >= low) {
        midle = (high + low) / 2;

        if (arr[midle] == key)
            return midle;
        if (arr[midle] > key)
            high = midle - 1;  // 前提是假设数组是从小到大排序，否则不确定是该加1还是减1
        else if (arr[midle] < key)
            low = midle + 1;
    }

    return (-1);

}

#ifdef __cplusplus
}
#endif


