#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/array.h"

using namespace std;

#ifndef LIST_H
#define LIST_H

struct list {
  int value;
  struct list * next;
};

struct dlist {
  int value;
  struct list * next;
  struct list * back;
};

int list_size(list * head){
  int size = 0;
  while(head){
    size++;
    head = head->next;
  }
  return size;
}

void print_list(list * head, string name = "List"){
  cout << name << " (" << list_size(head) << ") : ";
  while(head){
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

list * list_addition(list * head, int value){
  list * current;

  if(!head){
    head = (list *)malloc(sizeof(list));
    head->value = value;
    head->next = NULL;
    return head;
  }
  current = head;
  while(current->next){
    current = current->next;
  }
  list * new_node = (list *)malloc(sizeof(list));
  new_node->value = value;
  new_node->next = NULL;
  current->next = new_node;

  return head;
}

// optimised but change the list.
list * list_reverse_iterative(list * head){
  list * previous = NULL;
  list * current = head;
  list * next;

  while(current){
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  return previous;
}

// not optimised but won't change the list
list * list_reverse(list * head){
  if(!head) return NULL;
  if(!head->next) {
    list * new_node = (list *)malloc(sizeof(list));
    new_node->value = head->value;
    new_node->next = NULL;
    return new_node;
  }
  list * reverse = list_reverse(head->next);
  list * current = reverse;
  while(current->next){
    current = current->next;
  }
  list * new_node = (list *)malloc(sizeof(list));
  new_node->value = head->value;
  new_node->next = NULL;
  current->next = new_node;
  return reverse;
}

bool list_find(list * head, int value){
  list * current = head;
  while(current){
    if(current->value == value) return true;
    current = current->next;
  }
  return false;
}

list * make_list(int size, int min_value = INT_MIN, int max_value = INT_MAX){
  int * values = make_array(size, min_value, max_value);
  list * head = NULL;

  for(int i = 0; i < size; i++){
    head = list_addition(head, values[i]);
  }

  return head;
}

#endif