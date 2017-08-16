#include <iostream>
#include <cstdio>
using namespace std;

#ifndef BST_H
#define BST_H

#include "binary_tree.h"
#include "array.h"

#define SIZE 20

node * bst_addition(node * root, int value){
	node * current = NULL;
	node * previous = NULL;
	node * new_node = NULL;

	if(root == NULL){
		new_node = (node *)malloc(sizeof(node));
		new_node->value = value;
		new_node->left = new_node->right = NULL;
		return new_node;
	}

	current = root;
	while(current != NULL){
		if (value < current->value){
			previous = current;
			current = current->left;
		} else if (value > current->value) {
			previous = current;
			current = current->right;
		} else if (value == current->value) {
			// Duplicates values are not supported.
			return root;
		}
	}

	new_node = (node *)malloc(sizeof(node));
	new_node->value = value;
	new_node->left = new_node->right = NULL;

	if (value < previous->value){
		previous->left = new_node;
	} else if (value > previous->value) {
		previous->right = new_node;
	}

	return root;
}

node * make_bst(int size = SIZE, int min = INT_MIN/2, int max = INT_MAX/2){
	int * values = make_array_unique(size, min, max);
	node * root = NULL;

	for( int i = 0; i < size; i++ ){
		root = bst_addition(root, values[i]);
	}
	return root;
}

node * bst_search(node * root, int value){
  node * current = NULL;
  current = root;
  while(current){
    if(value == current->value){
      return current;
    } else if (value < current->value){
      current = current->left;
    } else if (value > current->value){
      current = current->right;
    }
  }
  return current;
}

void print_path(node * root, int value){
  while(root){
    cout << root->value << "->";
    if(value == root->value) break;
    else if(value < root->value) root = root->left;
    else if(value > root->value) root = root->right;
  }
  cout << endl;
}

void print_all_nodes_with_child(node * root){
  if(!root) return;
  cout << root->value;
  
  if(root->left){
    cout << " (" << root->left->value << ",";
  } else {
    cout << " (NIL,";
  }

  if(root->right){
    cout << root->right->value << ")" << endl;
  } else {
    cout << "NIL)" << endl;
  }

  print_all_nodes_with_child(root->left);
  print_all_nodes_with_child(root->right);
}

node * bst_minimum(node * root){
  if(!root) return NULL;
  while(root->left){
    root = root->left;
  }
  return root;
}

node * bst_maximum(node * root){
  if(!root) return NULL;
  while(root->right){
    root = root->right;
  }
  return root;
}

int bst_random_node(node * root){
  node * minimum = bst_minimum(root);
  node * maximum = bst_maximum(root);
  int key;
  while(true){
    key = rand()%(maximum->value) - (minimum->value);
    if( bst_search(root, key) ) break;
  }
  return key;
}

void print_leaf_nodes(node * root){
  if(!root) return;
  if(!root->left && !root->right){
    cout << root->value << " ";
  }
  print_leaf_nodes(root->left);
  print_leaf_nodes(root->right);
}

void bst_leaf_nodes(node * root){
  cout << "Leaf Nodes : ";
  print_leaf_nodes(root);
  cout << endl;
}

#endif