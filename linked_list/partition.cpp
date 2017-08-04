#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

list * partition_list(list * head, int x){
  list * current = head;
  list * new_head = head;
  list * previous = NULL;

  while(current){
    if(current->value < x){
      new_head = (list *)malloc(sizeof(list));
      new_head->value = current->value;
      new_head->next = head;
      head = new_head;
      if(current->next){
        current->value = current->next->value;
        current->next = current->next->next;
      } else {
        current = NULL;
        previous->next = NULL;
      }
    } else {
      previous = current;
      current = current->next;
    }
  }
  return new_head;
}

int main(){
  int x;
  cout << "Enter the value of x(partition) : ";
  cin >> x;
  list * linked_list = make_list(30, 1, 100);
  print_list(linked_list, "Input List");
  list * partitioned_list = partition_list(linked_list, x);
  print_list(partitioned_list, "Partitioned List");
}