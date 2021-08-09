#include <stdio.h>
#include <stdlib.h>

//이진 탐색 트리
//
//이진 탐색이 항상 동작하도록 구현하여 탐색 속도를 극대화시킨 자료구조
//항상 부모 노드가 왼쪽 자식 보다는 크고 오른쪽 자식 보다는 작다.
//한번 확인할 때마다 보아야 하는 원소의 개수가 절반씩 줄어든다는 점에서 완전 이진 트리인 경우 탐색 시간에 O(logN)의 시간 복잡도를 가진다.
//
//트리에서 데이터의 개수가 N개일 때 배열과 마찬가지로 O(N)의 공간만이 소요되며 삽입 및 삭제에 있어 일반적인 경우 기존의 배열을 이용하는 방식보다 효율적이다.데이터베이스등 대용량 저장 및 검색 자료구조로 많이 활용된다.






typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* insertNode(Node* root, int data) {
	if (root == NULL) { //root가 null이면 초기화
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->data = data;
		return root;
	}
	else {
		if (root->data > data) { //루트보다 데이터가 작으면 왼쪽에
			root->leftChild = insertNode(root->leftChild, data);
		}
		else { //크면 오른쪽에 삽입
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	return root;
}

Node* searchNode(Node* root, int data) {
	if (root == NULL)return NULL;
	if (root->data == data)return root; 
	else if (root->data > data)return searchNode(root->leftChild, data); 
	else return searchNode(root->rightChild, data);
}

void preorder(Node* root) {
	if (root == NULL)return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

Node* findMinNode(Node* root) {
	Node* node = root;
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}
	return node;
}

Node* deleteNode(Node* root, int data) {
	Node* node = NULL;
	if (root == NULL)return NULL;
	if (root->data > data)root->leftChild = deleteNode(root->leftChild, data);
	else if (root->data < data)root->rightChild = deleteNode(root->rightChild, data);
	else {
		if (root->leftChild != NULL && root->rightChild != NULL) {
			node = findMinNode(root->rightChild);
			root->data = node->data;
			root->rightChild = deleteNode(root->rightChild, node->data);
		}
		else {
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild; //왼쪽 자식 존재시 왼쪽을 오른쪽 자식 존재시 오른쪽을
			free(root); //자신을 해제하고 자식으로 대체
			return node;
		}
	}
	return root;
}

int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 42);
	root = insertNode(root, 5);
	root = insertNode(root, 88);
	root = insertNode(root, 20);
	root = deleteNode(root, 30);
	preorder(root);
	system("pause");
}
