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

int reverse(int num) {
    int result = 0;
    while(num > 0) {
        result = result * 10 + num % 10;
        num = num / 10;
    }
    return result;
}

// Calculate the largest palindrome number from multiplying two 3-digit numbers
int euler4() {
    int product = 0;
    for(int i = 999; i >= 100; i--) {
        for(int j = i; j >= 100; j--) {
            int potential = i * j;
            if(reverse(potential) == potential && potential > product) {
                product = potential;
            }
        }
    }
    return product;
}

bool divide(int num) {
    for(int i = 1; i < 20; i++) {
        if(num % i != 0) {
            return false;
        }
    }
    return true;
}

// What is the smallest number that can be 
// divided by each of the numbers from 1 to 10 w/o any remainder?
int euler5() {
    int result = 0;
    int num = 20;
    while(!divide(num)) {
        num++;
    }
    return num;
}

// Find the difference b/w the sum of the suqares of the 1st 100 natural numbers 
// and the square of the sum (sum 100 where n = 1 --> 100 and n^2)
long squareSum() {
    long result = 0;
    for(int i = 1; i <= 100; i++) {
        result += i * i;
    }
    return result;
}

long sumSquared() {
    long result = 0;
    for(int i = 1; i <= 100; i++) {
        result += i;
    }
    return result * result;
}
long euler6() {
    return sumSquared() - squareSum();
}

int main(void) {
  long result = euler6();
  printf("%ld\n", result);
  return 0;
}