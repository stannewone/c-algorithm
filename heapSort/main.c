#include <stdio.h>
#include <stdlib.h>

/*�q�[�v�\�[�g�u�̑ΏۂƂȂ�z��
���ۂɎg�p����̂�a[1]~a[MAX_HEAP]���݂ŁAa[0]�͎g�p���Ȃ����Ƃɒ���*/
#define MAX_HEAP 1000
/*�z��a�ɓo�^����Ă���v�f�̌�
�z��̂���a[1]~a[n]�ɗv�f�������Ă���*/
int a[10];
int n = 0;

/*�q�[�v�̐擪�̗v�fa[1]��K�v�ȂƂ���܂Œ��߂�*/
/*a[from]���q�[�v�̐擪�Aa[to]���q�[�v�̍Ō�̗v�f�Ƃ���*/
void downheap(int from, int to) {
    int i, j;
    int val;

    /*���߂���v�f�̒l��val�ɃZ�b�g���Ă���*/
    val = a[from];

    /*�����珉�߂āA��i���q�������Ă������J��Ԃ�*/
    i = from;
    while (i <= to/2) {
        /*��i�̎q�̂����������ق����j�Ƃ���*/
        j = i * 2;                     /*���̐�*/
        if (j+1 <= n && a[j] > a[j+1]) /*���̐߂̂ق����傫�����*/
            j++;                       /*�E�̐�*/
        /*�����A�e���q���傫���Ȃ��Ƃ����֌W�����藧�Ă΁A
        ����ȏ㒾�߂�K�v�͂Ȃ�*/
        if (val <= a[j])
            break;

        /*��i�ɐ�j�̒l�����āA��j�ɒ��ڂ���*/
        a[i] = a[j];
        i = j;
    }

    /*�擪�ɂ������v�f���i�ɓ����*/
    a[i] = val;
}

/*�z��a���q�[�v�\�[�g����
a[1]~a[n]���\�[�g���A�ŏI�I�ɂ͔z��S�̂��~���ɐ��񂳂��*/
void heap_sort()
{
    int i;
    int tmp;

    /*�{�g���A�b�v*/
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

/*�q�[�v����ŏ��̗v�f���폜����B�v�f�̒l��Ԃ�*/
int delete_min() {
    int val;
    /*�q�[�v����łȂ����Ƃ��m�F����*/
    if (n < 1) {
        fprintf(stderr, "�q�[�v����ł�\n");
        exit(1);
    }

    /*���̗v�f�����^�[���l�ɂ���*/
    val = a[1];

    /*�q�[�v�̍Ō�̗v�f��擪�Ɉړ�����*/
    a[1] = a[n--];

    /*�擪�Ɉړ������v�f��K�؂ȏꏊ�܂Œ��߂�*/
    downheap(1, n);
    return val;
}


/*�q�[�v����x�Ԗڂ̗v�f��K�v�ȏꏊ�܂ŕ����яオ�点��*/
void upheap(int x) {
    int val;

    /*�����яオ�点��v�f�̒l��val�ɓ���Ă���*/
    val = a[x];

    /*�v�f�����܂ŕ����яオ���Ă��Ȃ��A����
    �u�e���q���傫���v�ԌJ��Ԃ�*/
    while (x > 1 && a[x/2] > val) { /*�e�̒l�Ƃ��̗v�f�̒l���r����*/

        /*�e�̒l���q�Ɉڂ�*/
        a[x] = a[x/2];

        /*���ړ_��e�Ɉڂ�*/
        x /= 2;
    }

    /*�ŏI�I�ȗ��������悪���܂���*/
    a[x] = val; /*�e�̒l�͌��̗v�f�̒l�ł���*/
}

/*�q�[�v���ɗv�felem��o�^����*/
void insert(int elem) {
    /*�q�[�v�ɓo�^�ł���]�T������m�F����*/
    if (n >= MAX_HEAP) {
        fprintf(stderr, "����ȏ�q�[�v�ɗv�f��o�^�ł��܂���B");
        exit(1);
    }

    /*�v�f���Ƃ肠�����q�[�v�̍Ō�ɓ����*/
    a[++n] = elem;

    /*�ǉ������v�f�𕂂��яオ�点��*/
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
