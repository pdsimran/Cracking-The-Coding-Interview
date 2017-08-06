#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../maker/list.h"
#include "../maker/math.h"

using namespace std;

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

int main(){
  list * first = make_list(30, 1, 100);
  list * second = make_list(20, 1, 100);
  list * common = make_list(7, 1, 100);

  list * current = first;
  while(current->next){
    current = current->next;
  }
  current->next = common;

  current = second;
  while(current->next){
    current = current->next;
  }
  current->next = common;

  print_list(first, "first");
  print_list(second, "second");

  list * intersecting_node = list_intersection(first, second);
  if(intersecting_node){
    cout << "Yes! list are intersecting at node = " << intersecting_node->value << endl;
  } else {
    cout << "No! list are not intersecting." << endl;
  }
}