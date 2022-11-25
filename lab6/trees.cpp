#include <iostream>
#include "trees.h"

Node::Node(int data) {
	left = right = 0;
	this->data = data;
	size = 1;
}

int main() {
	Tree* tree = new Tree;
	tree->root = insert(tree, 0);
	int hui[] = { 1,2,3,4,5,6 };
	for (size_t i = 0; i < 6; i++)
	{
		insert(tree, rand() % (10*(i+1)));
	}
	
	
	symmetricOrder(tree->root);
}

Node* randomInsert(Node* previous, int data, Tree* tree)
{
	if (!previous) return new Node(data);
	if (rand() % (previous->size + 1) == 0) {
		if (previous == tree->root) {
			tree->root = insertRoot(previous, data);
			return tree->root;
		}
		return insertRoot(previous, data);
	}
	else if (data < previous->data) previous->left = randomInsert(previous->left, data, tree);
	else if (data > previous->data) previous->right = randomInsert(previous->right, data, tree);
	fixSize(previous);
	return previous;
}

int fixSize(Node* previous)
{
	return previous->size = getSize(previous->left) + getSize(previous->right) + 1;
}

int getSize(Node* previous)
{
	if (!previous) return 0;
	else return previous->size;
}

Node* insertRoot(Node* previous, int data)
{
	if (!previous) return new Node(data);
	if (data < previous->data) {
		previous->left = insertRoot(previous->left, data);
		return rotateRight(previous);
	}
	else
	{
		previous->right = insertRoot(previous->right, data);
		return rotateLeft(previous);
	}
}

Node* rotateLeft(Node* previous)
{
	Node* current = previous->right;
	if (!current) return previous;
	previous->right = current->left;
	current->left = previous;
	current->size = previous->size;
	fixSize(previous);
	return current;
}

Node* rotateRight(Node* previous)
{
	Node* current = previous->left;
	if (!current) return previous;
	previous->left = current->right;
	current->right = previous;
	current->size = previous->size;
	fixSize(previous);
	return current;
}

void symmetricOrder(Node* root)
{
	if (!root) return;
	symmetricOrder(root->left);
	std::cout << " " << root->data;
	symmetricOrder(root->right);
}

Node* insert(Tree* tree, int data)
{

	return randomInsert(tree->root, data, tree);
}
