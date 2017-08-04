#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

int find_kth_last(list * head, int k){
  int size = list_size(head);
  list * current = head;

  int count = 0;
  while(current){
    if( (size-k) == count ){
      return current->value;
    }
    current = current->next;
    count++;
  }
  return -1;
}

int find_kth_last_2(list * head, int k){
  list * current = head;
  list * next_current = head;

  int count = 0;
  while(next_current){
    if(count == k) break;
    count++;
    next_current = next_current->next;
  }

  if(count < k) return -1;
  else {
    while(next_current){
      current = current->next;
      next_current = next_current->next;
    }
    return current->value;
  }
}

int main(){
  int k;
  cout << "Enter the value of K : ";
  cin >> k;
  list * linked_list = make_list(4, 10, 99);
  print_list(linked_list, "Input List");
  int kth_last = find_kth_last(linked_list, k);
  cout << "Kth last element is : " << kth_last << endl;
  kth_last = find_kth_last_2(linked_list, k);
  cout << "Kth last element is : " << kth_last << endl;
}