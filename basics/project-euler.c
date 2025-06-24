#include <stdio.h>
#include <stdbool.h>

int euler1();
int euler2();
bool isPrime();

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

bool isPrime(int num) {
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

// What is the largest prime factor of the number 600851475143?
int euler3() {
    long target = 600851475143;
    long factor = 2;
    long largestPrime = 0;
    while(target > 1) {
        if(target % factor == 0) {
            if(isPrime(factor)) {
                largestPrime = factor;
                while(target % factor == 0) {
                    target /= factor;
                }
            }
        }
        factor++;
    }
    return largestPrime;
}

int main(void) {
  int result = euler3();
  printf("%d\n", result);
  return 0;
}