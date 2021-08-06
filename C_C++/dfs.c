#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001


//깊이 우선 탐색
//
//보다 깊은 것을 우선적으로 탐색하는 알고리즘
//기본적으로 전체 노드를 맹목적으로 탐색하고자 할 때 사용한다.
//스택 자료구조에 기초한다.
//모든 경우의 수를 탐색하고자 할 때 쉽게 사용 가능하다.



typedef struct {
	int index;
	struct Node* next;
}Node;

Node** a; //연결리스트(정점)이 여러개이기 때문에 이차원 포인터로 할당
int n, m, c[MAX_SIZE]; //c는 방문을 했는지 파악

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {
	if (c[x]) return; //특정 x인덱스의 노드에서확인
	c[x] = 1; //방문하면 1로 방문처리
	printf("%d ", x);
	Node* cur = a[x]->next;
	while (cur != NULL) {
		int next = cur->index;
		dfs(next);
		cur = cur->next;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));//정점의 개수만큼 할당
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d",& x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	dfs(1);
	system("pause");
}