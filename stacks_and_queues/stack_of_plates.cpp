#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class StackSet {
  public:

    StackSet(){
      stack_set.resize(1);
      current_stack = 0;
      capacity = 3;
    }

    void push(int value){
      if(stack_set[current_stack].size() == capacity){
        current_stack++;
        stack<int> new_stack;
        stack_set.push_back(new_stack);
      }
      stack_set[current_stack].push(value);
    }

    void pop(){
      if(stack_set[current_stack].size() == 0){
        current_stack--;
        stack_set.pop_back();
      }
      stack_set[current_stack].pop();
    }

    int top(){
      int top;
      if(stack_set[current_stack].empty()){
        top = stack_set[current_stack-1].top();
      } else {
        top = stack_set[current_stack].top();
      }
      cout << "top = " << top << endl;
      return top;
    }

  private:
     vector< stack<int> > stack_set;
     int current_stack;
     int capacity;
};

int main(){
  StackSet stack_set;
  stack_set.push(1); stack_set.top();
  stack_set.push(2); stack_set.top();
  stack_set.push(3); stack_set.top();
  stack_set.push(4); stack_set.top();
  stack_set.push(5); stack_set.top();

  stack_set.pop(); stack_set.top();
  stack_set.pop(); stack_set.top();
  stack_set.pop(); stack_set.top();
  stack_set.pop(); stack_set.top();
  stack_set.pop();
}