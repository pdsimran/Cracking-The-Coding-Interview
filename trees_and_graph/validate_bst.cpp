#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/bst.h"

using namespace std;

bool validate_bst(node * root, int min, int max){
  if(!root) return true;
  if( root->value < max && root->value > min){
    bool is_left_bst = validate_bst(root->left, min, root->value);
    bool is_right_bst = validate_bst(root->right, root->value, max);
    return (is_left_bst && is_right_bst);
  } else {
    return false;
  }
}

int main(){
  node * bst = make_bst(30,1,100);
  bool is_bst = validate_bst(bst, INT_MIN, INT_MAX);
  if(is_bst){
    cout << "Yes ! it's a BST" << endl;
  } else {
    cout << "No ! it's not a BST" << endl;
  }
}