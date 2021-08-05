#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
}

void preorder(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void inorder(Node* root) {
	if (root) {
		preorder(root->leftChild);
		printf("%d ", root->data);
		preorder(root->rightChild);
	}
}

void postorder(Node* root) {
	if (root) {
		preorder(root->leftChild);
		preorder(root->rightChild);
		printf("%d ", root->data);
	}
}