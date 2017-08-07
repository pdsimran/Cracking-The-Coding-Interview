#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

class MyQueue{

  public: 
    void push(int value){
      cout << "pushing " << value << " to the queue" << endl;
      front.push(value);
    }

    void pop(){
      if(back.empty()){
        copy_front_to_back();
      }
      back.pop();
    }

    int back_queue(){
      if(front.empty()){
        copy_back_to_front();
      }
      return front.top();
    }

    int front_queue(){
      if(back.empty()){
        copy_front_to_back();
      }
      return back.top();
    }

    int size(){
      return (front.size()+back.size());
    }

    bool empty(){
      return (front.empty() && back.empty());
    }

  private:
    stack<int> front;
    stack<int> back;

    void copy_front_to_back(){
      while(!front.empty()){
        int top = front.top();
        // cout << "** top = " << top << endl;
        front.pop();
        back.push(top);
      }
      //cout << "returning from the copy_front_to_back" << endl;
    }

    void copy_back_to_front(){
      while(!back.empty()){
        int top = back.top();
        back.pop();
        front.push(top);
      }
    }
};

int main(){
  MyQueue my_queue;
  my_queue.push(1);
  my_queue.push(2);
  my_queue.push(3);
  cout << my_queue.front_queue() << " : " << my_queue.back_queue() << endl;
  my_queue.pop();
  my_queue.pop();
  my_queue.push(4);
  cout << my_queue.front_queue() << " : " << my_queue.back_queue() << endl;
  my_queue.pop();
  my_queue.pop();
  my_queue.push(10);
  my_queue.push(20);
  my_queue.push(30);
  cout << my_queue.front_queue() << " : " << my_queue.back_queue() << endl;

}