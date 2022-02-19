# Random number generator

There is an ideal random number generator, which given a positive integer M can generate any real number between 0 to M, and [probability density function](http://en.wikipedia.org/wiki/Probability_density_function) is uniform in [0, M].

Given two numbers A and B and we generate x and y using the random number generator with uniform probability density function [0, A] and [0, B] respectively, what's the probability that x + y is less than C? where C is a positive integer.

## Input Format

The first line of the input is an integer N, the number of test cases.

N lines follow. Each line contains 3 positive integers A, B and C.

## Constraints

All the integers are no larger than 10000.

## Output Format

For each output, output a fraction that indicates the probability. The greatest common divisor of each pair of numerator and denominator should be 1.

## Sample Input

```
3
1 1 1
1 1 2
1 1 3
```

## Sample Output

```
1/2
1/1
1/1
```

## Source

Hackerrank - [Random number generator](https://www.hackerrank.com/challenges/random-number-generator/problem)
