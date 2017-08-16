#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

#include "../maker/bst.h"
#include "../maker/array.h"

using namespace std;

node * bst_from_array(vector<int > input, int start, int end){
  if(start > end) return NULL;
  if( start == end ){
    node * new_node = (node *)malloc(sizeof(node));
    new_node->value = input[start]; new_node->left = NULL; new_node->right = NULL;
    return new_node;
  }
  int mid = (end+start)/2;
  node * left_subtree = bst_from_array(input, start, mid-1);
  node * right_subtree = bst_from_array(input, mid+1, end);
  node * root = (node *)malloc(sizeof(node));
  root->value = input[mid];
  root->left = left_subtree;
  root->right = right_subtree;
  return root;
}

int main(){
  int * arr = make_array_unique(70, 1, 100);
  print_array(arr, 70);
  vector<int> input(arr, arr+70);
  sort(input.begin(), input.end());
  node * bst = bst_from_array(input, 0, input.size()-1);
  inorder(bst);
  int height = binary_tree_height(bst);
  cout << "Height = " << height << endl;
}