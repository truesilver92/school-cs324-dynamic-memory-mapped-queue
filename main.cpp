
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

  ulong max_size = 4096;
  int *array;
  ulong head;
  ulong tail;
  

  ArrayQueue(){

    array = new int[max_size];
    
    // set the head and tail to the begining
    head = (ulong)array;
    tail = (ulong)array;
  }

  // add item
  void enqueue(int item) {
    *(int*)tail = item;
    // move the tail forward and wrap around if at end
    tail = (tail + 1) % max_size;
  }

  // remove item
  int dequeue() {
    int item = *(int*)head;
    // clear it
    *(int*)head = 0;
    head = (head + 1) % max_size;
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

int main(){
  // run and test array implementation
  // create array version
  ArrayQueue aq = ArrayQueue();
  double time = When();
  arrayqueue_test(aq, 100);
  double time2 = When();
  std::cout << "ArrayQueue test 100 time:\n";
  std::cout << time2 - time;

  time = When();
  arrayqueue_test(aq, 1000);
  time2 = When();
  std::cout << "ArrayQueue test 1000 time:\n";
  std::cout << time2 - time;

  // run and test linked list version

  // run and test memory mapped version
}
