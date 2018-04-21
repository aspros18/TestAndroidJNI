//
// Created by aimar on 2018/4/21.
//

#include "algorithm.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


// 从头向尾遍历, 将最大数沉入如果后部
void bulle_sort(int *arr, int size)
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


#ifdef __cplusplus
}
#endif


