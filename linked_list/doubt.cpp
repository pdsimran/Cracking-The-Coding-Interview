#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

void change_list(list * head){
  // head->value = 200;   // change will visible
  // head->next = NULL;   // change will visible
  head = head->next;      // change will not visible
}

int main(){
  list * head = (list *)malloc(sizeof(list));
  head->value = 4;
  head->next = NULL;
  print_list(head);
  list * current = head;

  list * new_node = (list *)malloc(sizeof(list));
  new_node->value = 5;
  new_node->next = NULL;
  current->next = new_node;
  
  print_list(head, "After Adition");

  list * new_list = make_list(20, 1, 20);
  print_list(new_list, "new_list");
  change_list(new_list);
  print_list(new_list, "new_list_after_function call");
}