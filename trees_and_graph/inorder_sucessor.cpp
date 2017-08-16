#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/bst.h"

using namespace std;

int inorder_successor(node * root, int number){
  node * current = root;
  node * last_left;
  while(current){
    if(number == current->value){
      break;
    }else if(number < current->value){
      last_left = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }
  if(current){
    if(current->right){
      node * minimum =  bst_minimum(current->right);
      return minimum->value;
    } else{
      return last_left->value;
    }
  } else {
    return -1;
  }
}

int main(){
  node * bst = make_bst(30, 1, 100);
  inorder(bst);
  int count = 10;
  while(count > 0){
    int number = bst_random_node(bst);
    int sucessor = inorder_successor(bst, number);
    cout << sucessor << " is a sucessor of " << number << endl;
    count--;
  }
}