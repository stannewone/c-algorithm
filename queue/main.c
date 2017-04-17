#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// �z��Ŏ��������҂��s��

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
        error("�҂��s�񂪃t���Ȃ̂ŗv�f�������܂���\n");
    queue[rear] = x;
    rear = next(rear);
}
ELEM dequeue() {
    ELEM x;
    if(front == rear)
        error("�҂��s�񂪋�Ȃ̂ŗv�f�����o���܂���\n");
    x = queue[front];
    front = next(front);
    return x;
}
int empty() {
    return front == rear;
}
*/

// �z��������O�o�b�t�@�Ƃ��Ĉ������L���[�f�[�^�\��

#define QUEUE_SIZE 7

struct queue_data {
    int queue[QUEUE_SIZE]; // �҂��s���錾
    int front; //�擪
    int rear; //����
};
typedef struct queue_data queue_t; //�@�\��queue_data�̕ϐ�queue_t
#define next(n) (((n) + 1) % QUEUE_SIZE) // ���̑}���ʒu�A�����O�o�b�t�@�݂����s��

// �������A�\���̂��ł̓����o�[front��rear���O�ɂ���
static void init(queue_t *q) {
    q ->front = 0;
    q ->rear =0;
}
// �҂��s�񂪋󂩂ǂ����𒲂ׂ�
//�@��Ȃ�1�A��łȂ����0�����^�[��
int isEmpty (queue_t q) {
    return (q.front == q.rear); // �|�C���^�łȂ���΃h�b�g���Z�q��p����
}
// �҂��s��Ƀf�[�^������
int push(queue_t *q, int data) { // �\���̂̃|�C���^���Ɠ��ꂽ�����edata
    if (next(q ->rear) == q ->front)
        return (-1); // �҂��s�񂪈�t�Ȃ̂ŁA-1�����^�[��

    q ->queue[q ->rear] = data; // rear��data�ɂ���
    q ->rear = next(q ->rear); // rear��1��������
    return (0);
}
int pop(queue_t *q, int *data) { // �\���̂̃|�C���^�Ǝ��o�����e�Ɏw���|�C���^data
    if (q ->front == q ->rear) // ��ł����
        return (-1);
    *data = q ->queue[q ->front]; // �|�C���^data�̒l��front�̒l
    q ->front = next(q ->front); // fron����1��������

    return (0);
}
// �z��v�f�ʒu���҂��s��͈͂ł��邩�m�F����
static int is_use_range(queue_t *q, int id) {
    if ((id < q->rear) && (id >= q->front)) return (1);
    if ((id > q->rear) && (id >= q->front)&& (q->front > q->rear)) return (1);
    if ((id < q->rear) && (id < q->front) && (q->front > q->rear)) return (1);
}
// �҂��s��̗v�f���ꗗ�\������
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

    // �f�[�^������
    for (cnt = 1; cnt < 5; cnt++) {
        printf("enqueue %d : ", cnt);
        if (push(&q, cnt) != 0) {
            printf("Queue is full\n");
        } else {
            queue_print(&q);
        }
    }
    // �f�[�^�����o��
    for (cnt = 1; cnt < 4; cnt++) {
        if (pop(&q, &data) != 0) {
            printf("Queue is empty\n");
        } else {
            printf("dequeue %d : ", data);
            queue_print(&q);
        }
    }

    // ��x�f�[�^������
    for (cnt = 5; cnt < 10; cnt++) {
        printf("enqueue %d : ", cnt);
        if (push(&q, cnt) != 0) {
            printf("Queue is full\n");
        } else {
            queue_print(&q);
        }
    }
    // ��x�f�[�^�����o��
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
