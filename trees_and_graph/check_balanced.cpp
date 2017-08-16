#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "../maker/bst.h"

using namespace std;

int diff(int a, int b){
  if(a > b) return (a-b);
  else return (b-a);
}

int height_diff_check(int left_height, int right_height){
  if(diff(left_height, right_height) <= 1){
    return true;
  } else {
    return false;
  }
}

pair<int, bool> check_height_and_balance(node * root, pair<int, bool> p){
  if(!root){
    return p;
  }
  pair<int, bool> temp;
  temp.first = p.first + 1;
  temp.second = p.second;

  pair<int, bool> left_subtree = check_height_and_balance(root->left, temp);
  pair<int, bool> right_subtree = check_height_and_balance(root->right, temp);

  pair<int, bool> output;
  output.first = max(left_subtree.first, right_subtree.first);
  output.second = left_subtree.second && right_subtree.second && height_diff_check(left_subtree.first, right_subtree.first);
  return output;
}

bool check_balanced_bst(node * root){
  pair<int, bool> p;
  p.first = -1;
  p.second = true;
  p = check_height_and_balance(root, p);
  return p.second;
}

// copied from minimal_tree.cpp
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
  bool is_balanced = check_balanced_bst(bst);
  if(is_balanced){
    cout << "Yes ! BST is balanced" << endl;
  } else{
    cout << "No ! BST is not balanced" << endl;
  }
  bst = make_bst(40, 1, 100);
  is_balanced = check_balanced_bst(bst);
  if(is_balanced){
    cout << "Yes ! BST is balanced" << endl;
  } else{
    cout << "No ! BST is not balanced" << endl;
  }
}