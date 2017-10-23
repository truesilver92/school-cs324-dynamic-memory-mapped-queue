
#include <sys/time.h>
#include <iostream>

/* Return the current time in seconds, using a double precision number.       */

double When()

{

    struct timeval tp;

    gettimeofday(&tp, 0);

    return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);

}

class ArrayQueue {
public:

  int max_size = 40960;
  int *array;
  int head;
  int tail;
  

  ArrayQueue(){

    array = new int[max_size];
    
    // set the head and tail to the begining
    head = 0;
    tail = 0;
  }

  // add item
  void enqueue(int item) {
    array[tail] = item;
    // move the tail forward and wrap around if at end
    tail = (tail + 1) % max_size;
  }

  // remove item
  int dequeue() {
    int item = array[head];
    // clear it
    array[head] = 0;
    head = (head + 1) % max_size;
    return item;
  }
};

class Node {
public:
  Node *next;
  int content;
};

class LinkedQueue : public ArrayQueue {

public:

  Node *head;
  Node *tail;

  LinkedQueue(int item){
    *head = Node();
    tail = head;
    head->content = item;
  }

  void enqueue(int item){
    *(tail->next) = Node();
    tail->content = item;
    tail = tail->next;
  }

  int dequeue(){
    int item = head->content;
    head = head->next;
    return item;
  }
};

void arrayqueue_test(ArrayQueue &aq, int number_to_do){
  for(int i = 0; i < number_to_do; i++){
    aq.enqueue(1);
  }
  for(int i = 0; i < number_to_do; i++){
    aq.dequeue();
  }
}

void arrayqueue_test_multiplyer(ArrayQueue &aq, int number_to_do, int how_many_times){
  double total;
  for(int i = 0; i < how_many_times; i++){
    double time = When();
    arrayqueue_test(aq, number_to_do);
    double time2 = When();
    total = total + (time2 - time);
  }

  std::cout << "ArrayQueue test ";
  std::cout << number_to_do;
  std::cout << " enqueue then dequeue time average over ";
  std::cout << how_many_times;
  std::cout << ":\n";
  std::cout << total / how_many_times;
  std::cout << "\n";
}

int main(){
  // run and test array implementation
  // create array version
  ArrayQueue aq = ArrayQueue();
  arrayqueue_test_multiplyer(aq, 40000, 8500);

  // run and test linked list version

  // run and test memory mapped version
}
