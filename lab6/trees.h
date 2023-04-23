#pragma once
struct Node {
	int data;
	int size;
	Node* left;
	Node* right;
	Node(int data);
};
struct Tree {
	Node* root = 0;
};
//��������� ������� ������
int getSize(const Tree tree);
//������������ ����� ������
void symmetricOrder(const Tree tree);
//������� ������ ���� � ������
Node* insert(Tree &tree, int data);
//�������� ���� ������ �� ��������
void deleteElement(Tree &tree, int data);
//����� ���� ������ �� ��������
Node* find(Tree& tree, int data);
//��������� ������ ������
int getHeight(const Tree tree);
//��������� ����� ���� ����� �� ���� ������ ������
int getSumPathsToEvenNodes(Tree tree);