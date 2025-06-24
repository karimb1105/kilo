#include <stdio.h>

// Find the sum of all multiples of 3 or 5 below 1000
int euler1() {
    int sum = 0;
    for(int i = 0; i < 1000; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

// Find sum of even fib sequence terms <= 4 million
int euler2() {
    int sum = 0;
    int first = 1;
    int second = 2;
    int new = 2;
    while(new < 4000000) {
        if(new % 2 == 0) {
            sum += new;
        }
        second = first + second;
        first = new;
        new = second;
        printf("%d %d %d\n", first, second, new);
    }
    return sum;
}

int main(void) {
  printf("meow\n");
  int result1 = euler1();
  int result2 = euler2();
  printf("%d\n", result2);
  return 0;
}