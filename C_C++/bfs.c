#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

//너비 우선 탐색
//
//너비를 우선적으로 탐색하는 알고리즘
//맹목적으로 전체 노드를 탐색하고자 할 때 사용한다.
//큐 자료구조에 기초한다.
//고급 그래프 탐색에 자주 쓰인다.
//
//1.	탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다
//2.	큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드들을 모두 큐에 삽입하고, 방문 처리한다.
//3.	2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.





typedef struct {
	int index;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;
} Queue;

Node** a; //연결리스트(정점)이 여러개이기 때문에 이차원 포인터로 할당
int n, m, c[MAX_SIZE]; //n은 정점, m은 간선, c는 방문을 했는지 파악

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
	if (queue->count == 0) { //큐가 비어있다면 앞에 추가
		queue->front = node;
	}
	else { //큐가 비어있지 않다면 꼬리에 추가
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int queuePop(Queue* queue) {
	if (queue->count == 0) { 
		printf("큐 언더플로우가 발생했습니다. \n");
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
	q.front = q.rear = NULL; //큐 초기화
	q.count = 0;
	queuePush(&q, start); //시작 인덱스를 넣어줌
	c[start] = 1; //방문처리
	while (q.count != 0) {
		int x = queuePop(&q);
		printf("%d ", x);
		Node* cur = a[x]->next;
		while (cur != NULL) { //인접 노드 확인
			int next = cur->index;
			if (!c[next]) { //방문하지 않은 상태라면 큐에 넣음
				queuePush(&q, next);
				c[next] = 1;
			}
			cur = cur->next;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m); //정점 개수 간선 개수 입력
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