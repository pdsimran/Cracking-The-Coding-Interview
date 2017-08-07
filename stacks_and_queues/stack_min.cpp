#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <utility>

using namespace std;

stack< pair<int, int> > min_stack;

void pop(){
  min_stack.pop();
}

int top(){
  pair<int, int> top_element = min_stack.top();
  return top_element.first;
}

int min(){
  pair<int, int> top_element;
  top_element =  min_stack.top();
  cout << "min_element = " << top_element.second << endl;
  return top_element.second;
}

void push(int value){
  pair<int, int> new_element;
  if(min_stack.empty()){
    new_element = make_pair(value, value);
  } else {
    pair<int, int> top_element = min_stack.top();
    new_element.first = value;
    new_element.second = (value < top_element.second) ? value : top_element.second;
  }
  min_stack.push(new_element);
}

int main(){
  push(4);
  min();
  push(6);
  min();
  push(2);
  min();
  push(37);
  min();
  push(1);
  min();
  push(4);
  min();

  pop(); min();
  pop(); min();
  pop(); min();
  pop(); min();
  pop(); min();
  pop();
}