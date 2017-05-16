#include <stdio.h>
#include <stdlib.h>

/*�z��a[l]~a[r]�𕪊�����A�����̓Y������Ԃ�*/

int partition(int a[], int l, int r) {
    int i, j, pivot, t;

    /*�|�C���^i��j������������*/
    i = l - 1;
    j = r;

    /*�����΂�E�[�̗v�f�𐕎��ɂ���*/
    pivot = a[r];

    /*�|�C���^i��j���Ԃ���܂ŌJ��Ԃ�*/
    for(;;) {
        /*�|�C���^i���E�ɐi��*/
        while (a[++i] < pivot)
            ;
        /*�|�C���^j�����ɐi��*/
        while (i < --j && pivot < a[j])
            ;
        /*�|�C���^i��j���Ԃ������烋�[�v�𔲂���*/
        if (i >= j)
            break;
        /*i�̎w���v�f��j�̎w���v�f����������*/
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    /*a[i]�Ɛ�������������*/
    t = a[i];
    a[i] = a[r];
    a[r] = t;

    return i;
}

/*���ۂɃN�C�b�N�\�[�g���s���֐�*/
void quick_sort_1(int a[], int l, int r) {
    int v;

    /*���񂷂�v�f����Ȃ�A���ɂ����Ȃ��Ń��^�[������*/
    if (l >= r)
        return;

    v = partition(a, l, r);/*����v����ɕ�������*/
    quick_sort_1(a, l, v-1);/*���̕����z��a[l]~a[v-1]�𐮗񂷂�*/
    quick_sort_1(a, v+1, r);/*�E�̕����z��a[v-1]~a[r]�𐮗񂷂�*/
}

/*�N�C�b�N�\�[�g*/
void quick_sort(int a[], int n) {
    quick_sort_1(a, 0, n-1);
}
int main()
{
    int i;
    int num[] = {55, 3, 74, 20, 13, 87, 46, 30};
    printf("�O�F");
    for (i = 0; i < (sizeof(num)/sizeof(int)); i++)
        printf("%3d", num[i]);
    putchar('\n');

    quick_sort(num, (sizeof(num)/sizeof(int)));

    printf("�ρF");
    for (i = 0; i < (sizeof(num)/sizeof(int)); i++)
        printf("%3d", num[i]);
    putchar('\n');
    return 0;
}
