
#include <sys/time.h>

/* Return the current time in seconds, using a double precision number.       */

double When()

{

    struct timeval tp;

    gettimeofday(&tp, 0);

    return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);

}

class queue {
public:
  void enqueue(int item) {
    
  }
};

int main(){
  // run and test array implementation
  // create array version
  

  // run and test linked list version

  // run and test memory mapped version
}
