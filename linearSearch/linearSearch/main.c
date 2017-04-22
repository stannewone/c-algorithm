//
//  main.c
//  linearSearch
//
//  Created by stan on 17/4/22.
//  Copyright © 2017年 stan. All rights reserved.
//

#include <stdio.h>

#define ARRAY_NUM(a) (sizeof(a) / sizeof(a[0]))

/*素数の配列を作成する*/
static void array_prime_number (int *array, unsigned int array_size) {
    int array_pos = 0;
    int tmp = 0;
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
/*線形探索を行う*/
static int linear_search (int *array, unsigned int array_size, int target) {
    int i;
    for (i = 0; i < array_size; i++) {
        if (array[i] == target) {
            return (i);
        }
    }
    return (-1);
}
int main(int argc, const char * argv[]) {
    int rc = 0;
    int num[300];
    int key;
    
    array_prime_number(num, ARRAY_NUM(num));
    printf("一つの数を入力してください：");
    scanf("%d", &key);
    rc = linear_search(num, ARRAY_NUM(num), key);
    if (rc > 0) {
        printf("見つけます。\nnum[%d] = %d\n", rc, num[rc]);
    } else {
        printf("見つけません。\n");
    }
    return 0;
}
