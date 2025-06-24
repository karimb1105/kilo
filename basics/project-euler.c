#include <stdio.h>

int multiples();

int main(void) {
  printf("meow\n");
  int result = multiples();

  printf("%d\n", result);
  return 0;
}

// Find the sum of all multiples of 3 or 5 below 1000
int multiples() {
    int sum = 0;
    for(int i = 0; i < 1000; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}