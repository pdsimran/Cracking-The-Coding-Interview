#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

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
}