#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

//�ʺ� �켱 Ž��
//
//�ʺ� �켱������ Ž���ϴ� �˰���
//�͸������� ��ü ��带 Ž���ϰ��� �� �� ����Ѵ�.
//ť �ڷᱸ���� �����Ѵ�.
//��� �׷��� Ž���� ���� ���δ�.
//
//1.	Ž�� ���� ��带 ť�� �����ϰ� �湮 ó���� �Ѵ�
//2.	ť���� ��带 ���� �ش� ����� ���� ��� �߿��� �湮���� ���� ������ ��� ť�� �����ϰ�, �湮 ó���Ѵ�.
//3.	2���� ������ �� �̻� ������ �� ���� ������ �ݺ��Ѵ�.





typedef struct {
	int index;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;
} Queue;

Node** a; //���Ḯ��Ʈ(����)�� �������̱� ������ ������ �����ͷ� �Ҵ�
int n, m, c[MAX_SIZE]; //n�� ����, m�� ����, c�� �湮�� �ߴ��� �ľ�

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void queuePush(Queue* queue, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;
	if (queue->count == 0) { //ť�� ����ִٸ� �տ� �߰�
		queue->front = node;
	}
	else { //ť�� ������� �ʴٸ� ������ �߰�
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int queuePop(Queue* queue) {
	if (queue->count == 0) { 
		printf("ť ����÷ο찡 �߻��߽��ϴ�. \n");
		return -INF;
	}
	Node* node = queue->front;
	int index = node->index; 
	queue->front = node->next;
	free(node);
	queue->count--;
	return index;
}

void bfs(int start) {
	Queue q;
	q.front = q.rear = NULL; //ť �ʱ�ȭ
	q.count = 0;
	queuePush(&q, start); //���� �ε����� �־���
	c[start] = 1; //�湮ó��
	while (q.count != 0) {
		int x = queuePop(&q);
		printf("%d ", x);
		Node* cur = a[x]->next;
		while (cur != NULL) { //���� ��� Ȯ��
			int next = cur->index;
			if (!c[next]) { //�湮���� ���� ���¶�� ť�� ����
				queuePush(&q, next);
				c[next] = 1;
			}
			cur = cur->next;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m); //���� ���� ���� ���� �Է�
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	bfs(1);
	system("pause");
}