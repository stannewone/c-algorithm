#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[], int n) {
    int i, j, m, temp;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            /*a‚ðƒvƒŠƒ“ƒg‚·‚é*/
            printf("  [");
            for (m = 0; m < n; m++)
                printf("%3d", a[m]);
            printf("]\n");
        }
        printf("++[");
        for (m = 0; m < n; m++)
            printf("%3d", a[m]);
        printf("]\n");
    }
}
int main()
{
    int bs[] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30};
    bubble_sort(bs, sizeof(bs) / sizeof(int));
    return 0;
}
