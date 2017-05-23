#include <stdio.h>
#include <stdlib.h>

/*ヒープソート「の対象となる配列
実際に使用するのはa[1]~a[MAX_HEAP]飲みで、a[0]は使用しないことに注意*/
#define MAX_HEAP 1000
/*配列aに登録されている要素の個数
配列のうちa[1]~a[n]に要素が入っている*/
int a[10];
int n = 0;

/*ヒープの先頭の要素a[1]を必要なところまで沈める*/
/*a[from]をヒープの先頭、a[to]をヒープの最後の要素とする*/
void downheap(int from, int to) {
    int i, j;
    int val;

    /*沈められる要素の値をvalにセットしておく*/
    val = a[from];

    /*根から初めて、節iが子を持っている限り繰り返す*/
    i = from;
    while (i <= to/2) {
        /*節iの子のうち小さいほうを節jとする*/
        j = i * 2;                     /*左の節*/
        if (j+1 <= n && a[j] > a[j+1]) /*左の節のほうが大きければ*/
            j++;                       /*右の節*/
        /*もし、親が子より大きくないという関係が成り立てば、
        これ以上沈める必要はない*/
        if (val <= a[j])
            break;

        /*節iに節jの値を入れて、節jに注目する*/
        a[i] = a[j];
        i = j;
    }

    /*先頭にあった要素を節iに入れる*/
    a[i] = val;
}

/*配列aをヒープソートする
a[1]~a[n]をソートし、最終的には配列全体が降順に整列される*/
void heap_sort()
{
    int i;
    int tmp;

    /*ボトムアップ*/
    /*
    for (i = n/2; i >= 1; i--)
        downheap(i, n);
    print_array(a, (sizeof(a)/sizeof(int)));
    */

    for (i = n; i >= 2; i--) {
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        downheap(1, i-1);
    print_array(a, (sizeof(a)/sizeof(int)));
    }
}

/*ヒープから最小の要素を削除する。要素の値を返す*/
int delete_min() {
    int val;
    /*ヒープが空でないことを確認する*/
    if (n < 1) {
        fprintf(stderr, "ヒープが空です\n");
        exit(1);
    }

    /*根の要素をリターン値にする*/
    val = a[1];

    /*ヒープの最後の要素を先頭に移動する*/
    a[1] = a[n--];

    /*先頭に移動した要素を適切な場所まで沈める*/
    downheap(1, n);
    return val;
}


/*ヒープ中のx番目の要素を必要な場所まで浮かび上がらせる*/
void upheap(int x) {
    int val;

    /*浮かび上がらせる要素の値をvalに入れておく*/
    val = a[x];

    /*要素が根まで浮かび上がっていない、かつ
    「親が子より大きい」間繰り返す*/
    while (x > 1 && a[x/2] > val) { /*親の値とこの要素の値を比較する*/

        /*親の値を子に移す*/
        a[x] = a[x/2];

        /*注目点を親に移す*/
        x /= 2;
    }

    /*最終的な落ち着き先が決まった*/
    a[x] = val; /*親の値は元の要素の値である*/
}

/*ヒープ中に要素elemを登録する*/
void insert(int elem) {
    /*ヒープに登録できる余裕がある確認する*/
    if (n >= MAX_HEAP) {
        fprintf(stderr, "これ以上ヒープに要素を登録できません。");
        exit(1);
    }

    /*要素をとりあえずヒープの最後に入れる*/
    a[++n] = elem;

    /*追加した要素を浮かび上がらせる*/
    upheap(n);
}

void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    putchar('\n');
}
int main()
{
    insert(9);
    insert(13);
    insert(12);
    insert(18);
    insert(21);
    insert(5);
    insert(17);
    insert(20);
    insert(25);
    insert(15);
    print_array(a, (sizeof(a)/sizeof(int)));
    heap_sort();
    return 0;
}
