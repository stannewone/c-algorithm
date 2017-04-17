#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_GAKUSEI 2000
#define MAX_KAMOKU 400

/*
struct SEISEKI {
    struct SEISEKI *glink;
    struct SEISEKI *klink;
    struct GAKUSEI *gakusei;
    struct KAMOKU *kamoku;
    short seiseki;
};

struct GAKUSEI {
    struct SEISEKI *glink;
    char *name;
}gakusei[MAX_GAKUSEI];

struct KAMOKU {
    struct SEISEKI *klink;
    char *name;
}kamoku[MAX_KAMOKU];

// ������
void initialize() {
    int i;
     for (i = 0; i < MAX_GAKUSEI; i++) {
        gakusei[i].glink = NULL;
     }
     for (i = o; i < MAX_KAMOKU; i++) {
        kamoku[i].klink = NULL;
     }
}

// �w���ԍ����A�Ȗڔԍ����̐��т����ɂ���
void add(int x, int y, short a) {
    struct SEISEKI *p;

    if (p = (malloc(sizeof(struct SEISEKI))) == NULL)
        error("������������܂���");
    p ->glink = gakusei[x].glink;
    gakusei[x].glink = p;
    p ->klink = kamoku[y].klink;
    kamoku[y].klink = p;
    p ->gakusei = &gakusei[x];
    p ->kamoku = &kamoku[y];
    p ->seiseki = a;
}

// �w�����̉Ȗڂ��̐��т𓾂�i���C���Ă��Ȃ��Ƃ��́A-1��Ԃ��j
short get_seiseki(int x, int y) {
    struct SEISEKI *p;
    for (p = gakusei[x].glink; p != NULL; p = p ->glink)
    if (p ->kamoku == &kamoku[y]) {
        return (p ->seiseki);
    }
    return (-1);
}

// ����Ȗځi�Ȗڔԍ����j�𗚏C���Ă���w���̖��O�Ɛ��т��v�����g����
void print_gakusei(int x) {
    struct SEISEKI *p;
    for (p = kamoku[x].klink; p != NULL; p = p ->klink)
        printf("$s %d\n", p ->gakusei ->name, p ->seiseki);
}
*/

// �Z���̒�`�F�|�C���^�{�f�[�^
struct cell {
    struct cell *next; // �|�C���^
    int data; // �f�[�^
};
typedef struct cell cell_t;

// �V�K�Z���𐶐�����
// �V�K�Z���̃A�h���X��Ԃ��A���s�̏ꍇ��NULL��Ԃ�
cell_t * list_alloc(int data) {
    cell_t *new = NULL;// �V�K�Z���̖��O��new

    new = (cell_t *)malloc(sizeof(cell_t));
    if (new == NULL) {
        fprintf(stderr, "ERROR: list_alloc(): %s\n", strerror(errno));
        return (NULL);
    }
    new ->next = NULL;
    new ->data = data;
}

// ���X�g�����ɐV�K�Z����ǉ�����
int list_add(cell_t *header, int data) {
    cell_t *next = NULL;
    cell_t *prev = header;

    next = list_alloc(data);
    if (next == NULL)
        return (-1);

    while (prev ->next != NULL) {
        prev = prev ->next;
    }
    prev ->next = next;

    return (0);
}

// ���X�g�̗v�f�����ׂĉ������
void list_free (cell_t *header) {
    cell_t *temp = header;
    cell_t *swap = NULL;
    while (temp != NULL) {
       swap = temp ->next;
       free(temp);
       temp = swap;
    }
}

// ���X�g�̗v�f���ꗗ�\������
static void list_print(cell_t *header) {
    cell_t *p = header;
    printf("list {");
    while (p != NULL) {
        printf("%d", p ->data);
        p = p ->next;
    }
    printf("}\n");
}
int main()
{
    int cnt = 0;
    // �擪�Z����p�ӂ���
    cell_t *header = list_alloc(0);
    if (header == NULL)
        return (-1);
    // �v�f��ǉ�����
    for (cnt = 1; cnt < 10; cnt++) {
        list_add(header, cnt);
    }
    list_print(header);
    // ���X�g���������
    list_free(header);
    return 0;
}
