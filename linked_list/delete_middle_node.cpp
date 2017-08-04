#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

list * find_random_node(list * head){
  int size = list_size(head);
  int index = 1 + random()%(size-2);
  int count = 0;
  while(head){
    if(count == index) break;
    count++;
    head = head->next;
  }
  return head;
}

list * delete_middle_node(list * head){
  list * random_node = find_random_node(head);
  cout << "Random Node : " << random_node->value << endl;
  random_node->value = random_node->next->value;
  random_node->next = random_node->next->next;
  return head;
}

int main(){
  list * linked_list = make_list(30, 1, 99);
  print_list(linked_list, "Input List");
  list * result = delete_middle_node(linked_list);
  print_list(result, "Input List");
}