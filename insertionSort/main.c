#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int n) {
    int i, j, m, temp;

    for (i = 1; i < n; i++) {
        j = i;
        while (j >= 1 && a[j] < a[j - 1]) {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;

            printf(" [");
            for (m = 0; m < n; m++)
                printf("%3d", a[m]);
            printf("]\n");
        }
        printf("+[");
        for (m = 0; m < n; m++)
            printf("%3d", a[m]);
        printf("]\n");
    }
}
int main()
{
    int is[] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30};
    insertion_sort(is, sizeof(is)/sizeof(int));
    return 0;
}
