# Rectangular Game

You are given an infinite 2-d grid with the bottom left cell referenced as (1,1). All the cells contain a value of zero initially. Let's play a game?

The game consists of `N` steps wherein each step you are given two integers `a` and `b`. The value of each of the cells in the co-ordinate (u, v) satisfying 1 ≤ u ≤ a and 1 ≤ v ≤ b, is increased by 1. After `N` such steps, if `X` is the largest number amongst all the cells in the rectangular board, can you print the number of `X`'s in the board?

## Input Format

The first line of input contains a single integer N. N lines follow.
Each line contains two integers a and b separated by a single space.

## Output Format

Output a single integer - the number of `X`'s.

## Constraints

- 1 ≤ N ≤ 100
- 1 ≤ a ≤ 106
- 1 ≤ b ≤ 106

## Sample Input

```
3
2 3
3 7
4 1
```

## Sample Output

```
2
```

## Explanation

Assume that the following board corresponds to cells (i, j) where 1 ≤ i ≤ 4 and 1 ≤ j ≤ 7.

At the beginning board is in the following state:

```
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 
```

After the first step we will obtain:

```
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 1 1 0 0 0 0
1 1 1 0 0 0 0 
```

After the second step we will obtain:

```
0 0 0 0 0 0 0
1 1 1 1 1 1 1
2 2 2 1 1 1 1
2 2 2 1 1 1 1 
```

Finally, after the last step we will obtain:

```
1 0 0 0 0 0 0
2 1 1 1 1 1 1
3 2 2 1 1 1 1
3 2 2 1 1 1 1 
```

So, the maximum number is 3 and there are exactly two cells which correspond to 3. Hence 2.

## Hint

Find the intersection area from all of the rectangle.

## Source

Hackerrank - [Rectangular Game](https://www.hackerrank.com/challenges/rectangular-game/problem)
