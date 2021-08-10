#include <stdio.h>
#include <stdlib.h>


//AVL트리
//
//균형이 갖춰진 이진 트리를 의미한다.
//완전 이진 트리는 검색에 있어 O(logN)의 시간 복잡도를 유지할 수 있다.
//AVL트리는 간단한 구현과정으로 특정 이진 트리가 완전 이진 트리에 가까운 형태를 유지하도록 해준다.
//
//균형 인수라는 개념을 이용한다.
//균형인수 = | 왼쪽 자식 높이 – 오른쪽 자식 높이 |
//이 균형인수가 모든 노드에 대해 + 1, 0, -1이어야한다.해당하지 않는다면 회전을 통해 트리를 재구성해야한다.





int getMax(int a, int b) {
	if (a > b)return a;
	return b;
}

typedef struct {
	int data;
	int height; //높이를 저장해야 시간 복잡도를 보장 가능
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

int getHeight(Node* node) { //저장된 높이를 반환
	if (node == NULL) return 0;
	return node->height;
}

void setHeight(Node* node) {//회전을 수행한 이후 높이를 다시 계산
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDifference(Node* node) { //균형인수를 구하는 함수
	if (node == NULL) return 0;
	Node* leftChild = node->leftChild;
	Node* rightChild = node->rightChild;
	return getHeight(leftChild) - getHeight(rightChild);
}

Node* rotateLL(Node* node) {
	Node* leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	setHeight(node); //회전 이후 높이를 다시 계산
	return leftChild; //leftChild는 이후 setHeight()를 수행
}

Node* rotateRR(Node* node) {
	Node* rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	setHeight(node); 
	return rightChild; 
}

Node* rotateLR(Node* node) {
	Node* leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	setHeight(node->leftChild);
	return rotateLL(node);
}

Node* rotateRL(Node* node) {
	Node* rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	setHeight(node->rightChild);
	return rotateRR(node);
}

Node* balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		if (getDifference(node->leftChild) >= 1) {
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);
	return node;
}

Node* insertNode(Node* node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	else if (data < node->data) {
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {
		printf("데이터 중복이 발생했습니다. \n");
	}
	return node;
}

Node* root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		display(node->rightChild, level + 1);
		printf("\n");
		if (node == root) {
			printf("Root : ");
		}
		for (int i = 0; i < level && node != root; i++) {
			printf("   ");
		}
		printf("%d(%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}

int main(void) {
	root = insertNode(root, 7);
	root = insertNode(root, 6);
	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 9);
	root = insertNode(root, 8);
	root = insertNode(root, 12);
	root = insertNode(root, 16);
	display(root, 1); printf("\n");
	system("pause");
}