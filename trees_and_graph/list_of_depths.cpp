#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

#include "../maker/bst.h"
#include "../maker/list.h"

using namespace std;

vector<list *> list_all_depths(node * root){
  queue<node *> q;
  q.push(root);
  int current_level = 1;
  int next_level = 0;
  int depth = 0;
  vector<list *> output;

  while(!q.empty()){
    node * current = q.front();
    if(current->left){
      q.push(current->left);
      next_level++;
    }
    if(current->right){
      q.push(current->right);
      next_level++;
    }
    q.pop();
    current_level--;
    // cout << "Adding to the list" << endl;
    if(output.size() == depth){
      list * head = NULL;
      output.push_back(head);
    }
    output[depth] = list_addition(output[depth], current->value);

    if(current_level == 0){
      current_level = next_level;
      next_level = 0;
      depth++;
    }
  }
  return output;
}

int main(){
  node * binary_tree = make_bst(30, 1, 100);
  inorder(binary_tree);
  vector<list *> output = list_all_depths(binary_tree);
  for(int i = 0; i < output.size(); i++){
    // string depth(1,i+48);
    string list_name = "Depth : " + to_string(i);
    print_list(output[i], list_name);
  }
}