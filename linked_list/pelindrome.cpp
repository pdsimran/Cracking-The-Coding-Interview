#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

bool pelindrome(list * head){
  list * reverse = list_reverse(head);
  list * current_head = head;
  list * current_reverse = reverse;
  
  while(current_head){
    if(current_head->value != current_reverse->value) break;
    current_head = current_head->next;
    current_reverse = current_reverse->next;
  }
  bool answer = (!current_head) ? true : false;
  return answer;
}

int main(){
  list * first_list = make_list(15, 0, 40);
  list * first_list_reverse = list_reverse(first_list);
  list * current = first_list;
  while(current->next){
    current = current->next;
  }
  current->next = first_list_reverse;
  print_list(first_list, "Input List");
  bool answer = pelindrome(first_list);
  if(answer){
    cout << "Yes! list is pelindrome" << endl;
  } else {
    cout << "No! list is not pelindrome" << endl;
  }
}