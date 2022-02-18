# CamelCase

There is a sequence of words in [CamelCase](https://en.wikipedia.org/wiki/CamelCase) as a string of letters, , having the following properties:

- It is a concatenation of one or more words consisting of English letters.
- All letters in the first word are lowercase.
- For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.

Given `s`, determine the number of words in `s`.

## Example

```
s = oneTwoThree
```

There are `3` words in the string: 'one', 'Two', 'Three'.

## Function Description

Complete the camelcase function in the editor below.

camelcase has the following parameter(s):

- string s: the string to analyze

## Returns

- int: the number of words in `s`

## Input Format

A single line containing string `s`.

## Constraints

- 1 ≤ length of s ≤ 10^5

## Sample Input

```
saveChangesInTheEditor
```

## Sample Output

```
5
```

## Explanation

String `s` contains five words:

1. save
2. Changes
3. In
4. The
5. Editor

## Source

Hackerrank - [CamelCase](https://www.hackerrank.com/challenges/camelcase/problem)
