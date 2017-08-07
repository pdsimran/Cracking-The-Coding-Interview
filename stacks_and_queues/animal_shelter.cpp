#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "../maker/list.h"

struct list_t {
  int value;
  int type;
  struct list_t * next;
};

class AnimalShelter{

  public:
    void enqueue(int value, int type){
      if(queue == NULL){
        queue = (list_t *)malloc(sizeof(list_t));
        queue->value = value;
        queue->type = type;
        queue->next = NULL;
        front = queue;
        back = queue;
      } else {
        list_t * new_node = (list_t *)malloc(sizeof(list_t));
        new_node->value = value;
        new_node->type = type;
        new_node->next = NULL;
        back->next = new_node;
        back = new_node;
      }
    }

    list_t * dequeue_any(){
      list_t * new_front = front->next;
      list_t * answer = front;
      front->next = NULL;
      front = new_front;
      if(!front){
        back = NULL;
      }
      return answer;
    }

    list_t * dequeue_type(int type){
      list_t * previous = NULL;
      list_t * current = front;
      while(current){
        if(current->type == type){
          if(previous){
            previous->next = current->next;
            if(current == back){
              back = previous;
            }
            current->next = NULL;
          } else {
            front = front->next;
            current->next = NULL;
          }
          break;
        }
        previous = current;
        current = current->next;
      }
      return current;
    }

    void print_queue(){
      list_t * current = front;
      cout << "Queue : ";
      while(true){
        cout << "("<< current->value << ","<< current->type << ") ";
        if(current == back) break;
        current = current->next;
      }
      cout << endl;
    }

  private:
    list_t * queue;
    list_t * front;
    list_t * back;
};

int main(){
  AnimalShelter animal_shelter;
  animal_shelter.enqueue(1,0);
  animal_shelter.enqueue(1,1);
  animal_shelter.print_queue();
  animal_shelter.enqueue(2,0);
  animal_shelter.enqueue(2,1);
  animal_shelter.print_queue();
  animal_shelter.enqueue(3,0);
  animal_shelter.enqueue(3,1);
  animal_shelter.print_queue();
  animal_shelter.enqueue(4,0);
  animal_shelter.enqueue(4,1);
  animal_shelter.print_queue();

  animal_shelter.dequeue_any();
  animal_shelter.print_queue();
  animal_shelter.dequeue_any();
  animal_shelter.print_queue();
  animal_shelter.dequeue_any();
  animal_shelter.print_queue();
  animal_shelter.dequeue_any();
  animal_shelter.print_queue();

  animal_shelter.dequeue_type(1);
  animal_shelter.print_queue();
  animal_shelter.dequeue_type(1);
  animal_shelter.print_queue();
}