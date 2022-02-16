# The Coin Change Problem

Given an amount and the denominations of coins available, determine how many ways change can be made for amount. There is a limitless supply of each coin type.

## Example

```python
n = 3
c = [8,3,1,2]
```

There are `3` ways to make change for `n=3` : `{1, 1, 1}`, `{1, 2}`, and `{3}`.

## Function Description

Complete the `getWays` function in the editor below.

`getWays` has the following parameter(s):

- `int n`: the amount to make change for
- `int c[m]`: the available coin denominations

## Returns

- `int`: the number of ways to make change

## Input Format

The first line contains two space-separated integers `n` and `m`, where:

`n` is the amount to change

`m` is the number of coin types

The second line contains `m` space-separated integers that describe the values of each coin type.

## Constraints

* `1 <= c[i] <= 50`
* `1 <= n <= 250`
* `1 <= m <= 50`
* Each `c[i]` is guaranteed to be distinct.

## Hints

Solve overlapping subproblems using [Dynamic Programming](http://en.wikipedia.org/wiki/Dynamic_programming) (DP):
You can solve this problem recursively but will not pass all the test cases without optimizing to eliminate the [overlapping subproblems](http://en.wikipedia.org/wiki/Overlapping_subproblem). Think of a way to store and reference previously computed solutions to avoid solving the same subproblem multiple times. * Consider the degenerate cases:
- How many ways can you make change for `0` cents? - How many ways can you make change for `> 0` cents if you have no coins? * If you're having trouble defining your solutions store, then think about it in terms of the base case `(n=0)`. - The answer may be larger than a `32`-bit integer.

## Sample Input 0

```
4 3
1 2 3
```

## Sample Output 0

```
4
```

## Explanation 0

There are four ways to make change for `n=4` using coins with values given by `C = [1,2,3]`:

1. `{1, 1, 1, 1}`
2. `{1, 1, 2}`
3. `{2, 2}`
4. `{1, 3}`

## Sample Input 1

```
10 4
2 5 3 6
```

## Sample Output 1

```
5
```

## Explanation 1

There are five ways to make change for `n=10` units using coins with values given by `C = [2,5,3,6]`:

1. `{2,2,2,2,2}`
2. `{2,2,3,3}`
3. `{2,2,6}`
4. `{2,3,5}`
5. `{5,5}`

## Source

Hackerrank - [The Coin Change Problem](https://www.hackerrank.com/challenges/coin-change/problem)
