#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

using namespace std;

int list_to_number_reverse(list * head){
  list * current = head;
  int place_value = 1;
  int number = 0;

  while(current){
    number = number + place_value * current->value;
    place_value *= 10;
    current = current->next;
  }
  return number;
}

int list_to_number(list * head){
  list * current = head;
  int number = 0;
  bool trailing_zero_flag = true;
  while(current){
    if(trailing_zero_flag && current->value != 0) trailing_zero_flag = false;
    if(!trailing_zero_flag){
      number = number*10 + current->value;
    }
    current = current->next;
  }
  return number;
}

int sum_list_1(list * first, list * second){
  int number1 = list_to_number_reverse(first);
  int number2 = list_to_number_reverse(second);
  return number1 + number2;
}

int sum_list_2(list * first, list * second){
  int number1 = list_to_number(first);
  int number2 = list_to_number(second);
  return number1 + number2;
}

int main(){
  list * first_list = make_list(5, 0, 1);
  list * second_list = make_list(6, 0, 1);
  print_list(first_list, "First List");
  print_list(second_list, "Second List");
  int result = sum_list_1(first_list, second_list);
  cout << "Sum(backward numbers) = " << result << endl;
  result = sum_list_2(first_list, second_list);
  cout << "Sum(forward_number) = " << result << endl;
}