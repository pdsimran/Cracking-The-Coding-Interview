#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

#include "../maker/list.h"
#include "../stl/unordered_map.h"

using namespace std;

list * remove_duplicate(list * head){
  unordered_map<int, int> hash;
  list * previous = NULL;
  list * current = head;

  while(current){
    // If key is not present unordered map returns 0.
    int value = hash[current->value];
    value++;
    hash[current->value] = value;
    current = current->next;
  }
  current = head;
  while(current->next){
    if(hash[current->value] > 1){
      int value = hash[current->value];
      value--;
      hash[current->value] = value;
      current = current->next;
      if(previous){
        previous->next = current;
      } else {
        head = head->next;
      }
    } else {
      previous = current;
      current = current->next;
    }
  }
  return head;
}

list * remove_duplicate_recursion(list * head){
  if(!head) return NULL;
  bool found = list_find(head->next, head->value);
  if(found){
    return remove_duplicate_recursion(head->next);
  } else{
    head->next = remove_duplicate_recursion(head->next);
    return head;
  }
}

list * remove_duplicate_iteration(list * head){
  list * current = head;
  while(current){
    list * previous = current;
    list * runner = current->next;
    while(runner){
      if(runner->value == current->value){
        previous->next = runner->next;
        runner = runner->next;
      } else {
        previous = runner;
        runner = runner->next;
      }
    }
    current = current->next;
  }
  return head;
}

int main(){
  list * linked_list = make_list(30, 1, 20);
  print_list(linked_list, "Input List");
  list * result = remove_duplicate(linked_list);
  print_list(result, "List After Duplicate Removed");
  result = remove_duplicate_recursion(linked_list);
  print_list(result, "List After Duplicate Removed");
  result = remove_duplicate_iteration(linked_list);
  print_list(result, "List After Duplicate Removed");
}