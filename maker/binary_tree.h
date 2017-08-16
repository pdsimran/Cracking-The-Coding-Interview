#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef BINARY_TREE
#define BINARY_TREE

struct node {
	int value;
	struct node * left;
	struct node * right;
};

void inorder_traversal(node * root){
	if (root == NULL) return;
	inorder_traversal(root->left);
	cout << root->value << " ";
	inorder_traversal(root->right);
}

void inorder(node * root){
	cout << "Inorder : ";
	inorder_traversal(root);
	cout << endl;
}

int _binary_tree_height(node * root, int height){
	if(!root) return height;
	int left_height = _binary_tree_height(root->left, height+1);
	int right_height = _binary_tree_height(root->right, height+1);
	int tree_height = (left_height > right_height) ? left_height : right_height;
	return tree_height;
}

// Null has height -1
// a single node(just leaf node) has height 0
int binary_tree_height(node * root){
	int height = -1;
	return _binary_tree_height(root, height);
}

#endif