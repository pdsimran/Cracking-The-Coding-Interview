#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

/*
  1) function do not change the stack state if passed by value
  2) Segmentation fault:11 comes If you pop on empty stack
  3) Segmentation fault:11 comes If try to store the top element of stack & stack is empty
*/

void push(stack<int> my_stack, int value){
  my_stack.push(value);
}

int main(){
  stack<int> my_stack;
  push(my_stack, 1);
  push(my_stack, 2);
  if(my_stack.empty()){
    cout << "Yes! stack is empty now." << endl;
  }
  // int a = my_stack.top();
  // my_stack.pop();
  int size = my_stack.size();
  cout << "size = " << size << endl;
}