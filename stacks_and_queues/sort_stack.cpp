#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> push_stack(stack<int> target, stack<int> source){
  while(!source.empty()){
    int top = source.top();
    source.pop();
    target.push(top);
  }
  return target;
}

stack<int> reverse_stack(stack<int> my_stack){
  if(my_stack.size() < 1) return my_stack;
  stack<int> result;
  return push_stack(result, my_stack);
}

stack<int> sort_stack(stack<int> my_stack){
  if(my_stack.size() < 1) return my_stack;
  int mid = my_stack.top();
  my_stack.pop();

  stack<int> smaller;
  stack<int> larger;

  while(!my_stack.empty()){
    int top = my_stack.top();
    if(top < mid){
      smaller.push(top);
    } else {
      larger.push(top);
    }
    my_stack.pop();
  }

  smaller = sort_stack(smaller);
  larger = sort_stack(larger);
  smaller = reverse_stack(smaller);
  larger = reverse_stack(larger);

  stack<int> sorted_stack;
  sorted_stack = push_stack(sorted_stack, larger);
  sorted_stack.push(mid);
  sorted_stack = push_stack(sorted_stack, smaller);
  return sorted_stack;
}

int main(){
  stack<int> my_stack;
  my_stack.push(2);
  my_stack.push(23);
  my_stack.push(11);
  my_stack.push(17);
  my_stack.push(49);
  my_stack.push(20);

  my_stack = sort_stack(my_stack);
  cout << "Sorted Order stack : " << endl;
  while(!my_stack.empty()){
    int top = my_stack.top();
    cout << top << " ";
    my_stack.pop();
  }
  cout << endl;
}