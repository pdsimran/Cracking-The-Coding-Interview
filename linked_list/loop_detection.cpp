#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"
#include "../maker/math.h"

using namespace std;

// copied from intersection.cpp
list * list_intersection(list * first, list * second){
  int first_size = list_size(first);
  int second_size = list_size(second);

  list * smaller;
  list * bigger;

  if(first_size < second_size){
    smaller = first;
    bigger = second;
  } else {
    smaller = second;
    bigger = first;
  }

  int count = 0;
  while(count < diff_abs(first_size, second_size)){
    bigger = bigger->next;
    count++;
  }

  while(bigger){
    if(bigger == smaller) break;
    bigger = bigger->next;
    smaller = smaller->next;
  }
  return bigger;
}

list * loop_detection(list * head){
  list * runner = head;
  list * runner2 = head;

  while(runner2 && runner2->next){
    runner = runner->next;
    runner2 = runner2->next->next;
    if(runner == runner2) break;
  }

  if( !runner2 || !runner2->next ){
    return NULL;
  } else {
    list * second_head = runner2->next;
    runner2->next = NULL;
    return list_intersection(head, second_head);
  }
}

int main(){
  list * first = make_list(25, 1, 100);
  list * loop = make_list(10, 1, 100);

  print_list(first, "first");
  print_list(loop, "loop");

  list * current = first;
  while(current->next){
    current = current->next;
  }
  current->next = loop;

  list * current2 = loop;
  while(current2->next){
    current2 = current2->next;
  }
  current2->next = current;

  list * loop_start = loop_detection(first);
  if(loop_start){
    cout << "Loop start at the node = " << loop_start->value << endl;
  } else {
    cout << "Loop is not present in the list" << endl;
  }

}