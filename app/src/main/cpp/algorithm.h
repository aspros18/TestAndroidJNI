//
// Created by aimar on 2018/4/21.
//

#ifndef ___ALGORITHM_H__
#define ___ALGORITHM_H__

#ifdef __cplusplus
extern "C" {
#endif

extern void swap(int *a, int *b);

// 插入排序 平均时间O(n^2)
extern void insert_sort(int *arr, int len);

// 冒泡排序 平均时间O(n^2)
extern void bubble_sort(int *arr, int size);

// 快速排序 平均时间O(nlog2n)
extern void quick_sort(int *arr, int offset, int len);

// 归并排序 平均时间O(nlog2n)
extern void merge_sort(int arr[], int start, int end);

#ifdef __cplusplus
}
#endif

#endif //___ALGORITHM_H__
