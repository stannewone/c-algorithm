//
//  main.c
//  binarySearch
//
//  Created by stan on 17/4/22.
//  Copyright © 2017年 stan. All rights reserved.
//

#include <stdio.h>
#define ARRAY_NUM(a) (sizeof(a) / sizeof(a[0]))

/*素数の配列を作成する*/
static void array_prime_number(int *array, unsigned int array_size) {
    int array_pos = 0;
    int tmp;
    int i, j;
    
    for (i = 1; array_pos <= array_size; i++) {
        tmp = 0;
        for (j = 1; j <= i; j++) {
            if ((i % j) == 0) {
                tmp++;
            }
        }
        if (tmp == 2) {
            array[array_pos] = i;
            array_pos++;
        }
    }
    return;
}
/*ループを用いた二分探索*/
static int binary_search1(int *array, unsigned int array_size, int target) {
    int low = 0;
    int middle = 0;
    int high = array_size - 1;
    
    while (low <= high) {
        middle = (low + high) / 2;
        if (array[middle] == target) {
            return middle;
        } else if (array[middle] > target) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return (-1);
}
/*再帰を用いる二分探索*/
static int binary_search2(int *array, unsigned int array_size, int low, int high, int target) {
    int middle = (low + high) / 2;
    if (array[middle] == target) {
        return middle;
    } else if (array[middle] > target) {
        return binary_search2(array, (high - low + 1), low, middle - 1, target);
    } else {
        return binary_search2(array, (high - low + 1), middle + 1, high, target);
    }
}
int main(int argc, const char * argv[]) {
    int rc1, rc2 = 0;
    int num[300];
    int key = 0;
    
    array_prime_number(num, ARRAY_NUM(num));
    printf("一つの数を入力してください：");
    scanf("%d", &key);
    
    rc1 = binary_search1(num, ARRAY_NUM(num), key);
    if (rc1 > 0) {
        printf("方法一で見つけます。\nnum[%d] = %d\n", rc1, num[rc1]);
    } else {
        printf("方法一で見つけません。\n");
    }
    printf("-------------------\n");
    rc2 = binary_search1(num, ARRAY_NUM(num), key);
    if (rc2 > 0) {
        printf("方法二で見つけます。\nnum[%d] = %d\n", rc2, num[rc2]);
    } else {
        printf("方法二で見つけません。\n");
    }
    return 0;
}
