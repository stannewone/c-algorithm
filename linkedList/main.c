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

// 初期化
void initialize() {
    int i;
     for (i = 0; i < MAX_GAKUSEI; i++) {
        gakusei[i].glink = NULL;
     }
     for (i = o; i < MAX_KAMOKU; i++) {
        kamoku[i].klink = NULL;
     }
}

// 学生番号ｘ、科目番号ｙの成績をあにする
void add(int x, int y, short a) {
    struct SEISEKI *p;

    if (p = (malloc(sizeof(struct SEISEKI))) == NULL)
        error("メモリが足りません");
    p ->glink = gakusei[x].glink;
    gakusei[x].glink = p;
    p ->klink = kamoku[y].klink;
    kamoku[y].klink = p;
    p ->gakusei = &gakusei[x];
    p ->kamoku = &kamoku[y];
    p ->seiseki = a;
}

// 学生ｘの科目ｙの成績を得る（履修していないときは、-1を返す）
short get_seiseki(int x, int y) {
    struct SEISEKI *p;
    for (p = gakusei[x].glink; p != NULL; p = p ->glink)
    if (p ->kamoku == &kamoku[y]) {
        return (p ->seiseki);
    }
    return (-1);
}

// ある科目（科目番号ｘ）を履修している学生の名前と成績をプリントする
void print_gakusei(int x) {
    struct SEISEKI *p;
    for (p = kamoku[x].klink; p != NULL; p = p ->klink)
        printf("$s %d\n", p ->gakusei ->name, p ->seiseki);
}
*/

// セルの定義：ポインタ＋データ
struct cell {
    struct cell *next; // ポインタ
    int data; // データ
};
typedef struct cell cell_t;

// 新規セルを生成する
// 新規セルのアドレスを返す、失敗の場合はNULLを返す
cell_t * list_alloc(int data) {
    cell_t *new = NULL;// 新規セルの名前はnew

    new = (cell_t *)malloc(sizeof(cell_t));
    if (new == NULL) {
        fprintf(stderr, "ERROR: list_alloc(): %s\n", strerror(errno));
        return (NULL);
    }
    new ->next = NULL;
    new ->data = data;
}

// リスト末尾に新規セルを追加する
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

// リストの要素をすべて解放する
void list_free (cell_t *header) {
    cell_t *temp = header;
    cell_t *swap = NULL;
    while (temp != NULL) {
       swap = temp ->next;
       free(temp);
       temp = swap;
    }
}

// リストの要素を一覧表示する
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
    // 先頭セルを用意する
    cell_t *header = list_alloc(0);
    if (header == NULL)
        return (-1);
    // 要素を追加する
    for (cnt = 1; cnt < 10; cnt++) {
        list_add(header, cnt);
    }
    list_print(header);
    // リストを解放する
    list_free(header);
    return 0;
}
