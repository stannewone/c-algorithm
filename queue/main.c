#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 配列で実現した待ち行列

/*
typedef long ELEM;
#define QUEUE_SIZE 100
ELEM queue[QUEUE_SIZE];
int front;
int rear;

#define next(a) (((a) + 1) % QUEUE_SIZE)

void error(char *s) {
    fprintf(stderr, s);
    exit(1);
}
void init() {
    front = rear = 0;
}
void enqueue(ELEM x) {
    if(next(rear) == front)
        error("待ち行列がフルなので要素を入れられません\n");
    queue[rear] = x;
    rear = next(rear);
}
ELEM dequeue() {
    ELEM x;
    if(front == rear)
        error("待ち行列が空なので要素を取り出せません\n");
    x = queue[front];
    front = next(front);
    return x;
}
int empty() {
    return front == rear;
}
*/

// 配列をリングバッファとして扱ったキューデータ構造

#define QUEUE_SIZE 7

struct queue_data {
    int queue[QUEUE_SIZE]; // 待ち行列を宣言
    int front; //先頭
    int rear; //末尾
};
typedef struct queue_data queue_t; //　構造queue_dataの変数queue_t
#define next(n) (((n) + 1) % QUEUE_SIZE) // 次の挿入位置、リングバッファみたい行列

// 初期化、構造体ｑではメンバーfrontとrearを０にする
static void init(queue_t *q) {
    q ->front = 0;
    q ->rear =0;
}
// 待ち行列が空かどうかを調べる
//　空なら1、空でなければ0をリターン
int isEmpty (queue_t q) {
    return (q.front == q.rear); // ポインタでなければドット演算子を用いる
}
// 待ち行列にデータを入れる
int push(queue_t *q, int data) { // 構造体のポインタｑと入れたい内容data
    if (next(q ->rear) == q ->front)
        return (-1); // 待ち行列が一杯なので、-1をリターン

    q ->queue[q ->rear] = data; // rearがdataにする
    q ->rear = next(q ->rear); // rearを1増加する
    return (0);
}
int pop(queue_t *q, int *data) { // 構造体のポインタと取り出す内容に指すポインタdata
    if (q ->front == q ->rear) // 空であれば
        return (-1);
    *data = q ->queue[q ->front]; // ポインタdataの値はfrontの値
    q ->front = next(q ->front); // fronｔを1増加する

    return (0);
}
// 配列要素位置が待ち行列範囲であるか確認する
static int is_use_range(queue_t *q, int id) {
    if ((id < q->rear) && (id >= q->front)) return (1);
    if ((id > q->rear) && (id >= q->front)&& (q->front > q->rear)) return (1);
    if ((id < q->rear) && (id < q->front) && (q->front > q->rear)) return (1);
}
// 待ち行列の要素を一覧表示する
static void queue_print(queue_t *q) {
    int cnt;
    printf("queue [");
    for (cnt = 0; cnt < QUEUE_SIZE; cnt++) {
        if (is_use_range(q, cnt)) {
            printf("%2d", q->queue[cnt]);
        } else {
            printf("%2c", '.');
        }
    }
    printf("]\n");
}
int main()
{
    queue_t q;
    int data = 0;
    int cnt;

    init(&q);

    // データを入れる
    for (cnt = 1; cnt < 5; cnt++) {
        printf("enqueue %d : ", cnt);
        if (push(&q, cnt) != 0) {
            printf("Queue is full\n");
        } else {
            queue_print(&q);
        }
    }
    // データを取り出す
    for (cnt = 1; cnt < 4; cnt++) {
        if (pop(&q, &data) != 0) {
            printf("Queue is empty\n");
        } else {
            printf("dequeue %d : ", data);
            queue_print(&q);
        }
    }

    // 二度データを入れる
    for (cnt = 5; cnt < 10; cnt++) {
        printf("enqueue %d : ", cnt);
        if (push(&q, cnt) != 0) {
            printf("Queue is full\n");
        } else {
            queue_print(&q);
        }
    }
    // 二度データを取り出す
    for (cnt = 1; cnt < 4; cnt++) {
        if (pop(&q, &data) != 0) {
            printf("Queue is empty\n");
        } else {
            printf("dequeue %d : ", data);
            queue_print(&q);
        }
    }
    return 0;
}
