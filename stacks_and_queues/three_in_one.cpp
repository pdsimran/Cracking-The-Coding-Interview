#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define STACK_SIZE 10000
#define STACK_COUNT 3

int stack[STACK_SIZE];
int stack_start[STACK_COUNT];
int stack_top[STACK_COUNT];

void print_status(){
  for(int i = 0; i < STACK_COUNT; i++){
    cout << "("<< stack_start[i] << "," << stack_top[i] << ")" << endl;
  }
}

void initialize_stack(){
  for(int i = 0; i < STACK_COUNT; i++){
    stack_start[i] = (i*STACK_SIZE)/STACK_COUNT;
  }
  for(int i = 0; i < STACK_COUNT; i++){
    stack_top[i] = stack_start[i];
  }
}

void print_stacks(){
  cout << "*************************" << endl;
  for(int i = 0; i < STACK_COUNT; i++){
    cout << "Stack - " << (i+1) << " : ";
    for(int j = stack_start[i]; j < stack_top[i]; j++ ){
      cout << stack[j] << " ";
    }
    cout << endl;
  }
}

int top(int stack_num){
  return stack[stack_top[stack_num]-1];
}

void push(int stack_num, int value){
  stack[stack_top[stack_num]] = value;
  stack_top[stack_num] = stack_top[stack_num] + 1;
}

bool empty(int stack_num){
  return (stack_start[stack_num] == stack_top[stack_num]);
}

void pop(int stack_num){
  if(empty(stack_num)){
    cout << "Cannot be poped from empty stack - " << stack_num << endl;
    return;
  }
  stack_top[stack_num] = stack_top[stack_num]-1;
}

int main(){
  initialize_stack();
  push(2, 100);
  push(2, 99);
  push(2, 98);
  pop(2);
  push(2,97);

  push(1, 37);
  push(1, 36);
  push(1, 35);
  push(1, 34);
  pop(1);
  pop(1);
  pop(1);
  push(1,33);

  push(0, 1);
  push(0, 2);
  push(0, 3);
  push(0, 4);
  pop(0);
  push(0,5);
  print_stacks();
}