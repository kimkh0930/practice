#include <stdio.h>
#include <stdlib.h>

//���� Ž�� Ʈ��
//
//���� Ž���� �׻� �����ϵ��� �����Ͽ� Ž�� �ӵ��� �ش�ȭ��Ų �ڷᱸ��
//�׻� �θ� ��尡 ���� �ڽ� ���ٴ� ũ�� ������ �ڽ� ���ٴ� �۴�.
//�ѹ� Ȯ���� ������ ���ƾ� �ϴ� ������ ������ ���ݾ� �پ��ٴ� ������ ���� ���� Ʈ���� ��� Ž�� �ð��� O(logN)�� �ð� ���⵵�� ������.
//
//Ʈ������ �������� ������ N���� �� �迭�� ���������� O(N)�� �������� �ҿ�Ǹ� ���� �� ������ �־� �Ϲ����� ��� ������ �迭�� �̿��ϴ� ��ĺ��� ȿ�����̴�.�����ͺ��̽��� ��뷮 ���� �� �˻� �ڷᱸ���� ���� Ȱ��ȴ�.






typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* insertNode(Node* root, int data) {
	if (root == NULL) { //root�� null�̸� �ʱ�ȭ
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->data = data;
		return root;
	}
	else {
		if (root->data > data) { //��Ʈ���� �����Ͱ� ������ ���ʿ�
			root->leftChild = insertNode(root->leftChild, data);
		}
		else { //ũ�� �����ʿ� ����
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
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild; //���� �ڽ� ����� ������ ������ �ڽ� ����� ��������
			free(root); //�ڽ��� �����ϰ� �ڽ����� ��ü
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
