#include <stdio.h>
#include <stdlib.h>
void selection_sort(int a[], int n) {
    int i, j, m, temp, lowest, lowkey;

    for (i = 0; i < n; i++){
        lowest = i;
        for (j = i + 1; j < n; j++) {
            if (a[lowest] > a[j]) {
                lowest = j;
            }
        }
        temp = a[i];
        a[i] = a[lowest];
        a[lowest] = temp;

        printf("[");
        for (m = 0; m < n; m++)
            printf("%3d", a[m]);
        printf("]\n");
    }

}
int main()
{
    int ss[] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30};
    selection_sort(ss, sizeof(ss) / sizeof(int));
    return 0;
}
