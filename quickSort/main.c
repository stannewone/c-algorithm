#include <stdio.h>
#include <stdlib.h>

/*配列a[l]~a[r]を分割する、枢軸の添え字を返す*/

int partition(int a[], int l, int r) {
    int i, j, pivot, t;

    /*ポインタiとjを初期化する*/
    i = l - 1;
    j = r;

    /*いちばん右端の要素を枢軸にする*/
    pivot = a[r];

    /*ポインタiとjをぶつかるまで繰り返す*/
    for(;;) {
        /*ポインタiを右に進む*/
        while (a[++i] < pivot)
            ;
        /*ポインタjを左に進む*/
        while (i < --j && pivot < a[j])
            ;
        /*ポインタiとjがぶつかったらループを抜ける*/
        if (i >= j)
            break;
        /*iの指す要素とjの指す要素を交換する*/
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    /*a[i]と枢軸を交換する*/
    t = a[i];
    a[i] = a[r];
    a[r] = t;

    return i;
}

/*実際にクイックソートを行う関数*/
void quick_sort_1(int a[], int l, int r) {
    int v;

    /*整列する要素が一つなら、何にもしないでリターンする*/
    if (l >= r)
        return;

    v = partition(a, l, r);/*枢軸vを基準に分割する*/
    quick_sort_1(a, l, v-1);/*左の部分配列a[l]~a[v-1]を整列する*/
    quick_sort_1(a, v+1, r);/*右の部分配列a[v-1]~a[r]を整列する*/
}

/*クイックソート*/
void quick_sort(int a[], int n) {
    quick_sort_1(a, 0, n-1);
}
int main()
{
    int i;
    int num[] = {55, 3, 74, 20, 13, 87, 46, 30};
    printf("前：");
    for (i = 0; i < (sizeof(num)/sizeof(int)); i++)
        printf("%3d", num[i]);
    putchar('\n');

    quick_sort(num, (sizeof(num)/sizeof(int)));

    printf("済：");
    for (i = 0; i < (sizeof(num)/sizeof(int)); i++)
        printf("%3d", num[i]);
    putchar('\n');
    return 0;
}
