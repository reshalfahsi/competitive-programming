# Basic Statistics Warmup

You are given an array of N integers separated by spaces, all in one line.

Display the following:

1. **Mean (m)**: The average of all the integers.
2. **Median of this array**: In case, the number of integers is odd, the middle element; else, the average of the middle two elements.
3. **Mode**: The element(s) which occurs most frequently. If multiple elements satisfy this criteria, display the numerically smallest one.
4. **Standard Deviation (SD)**.

```
SD = (((x1-m)2+(x2-m)2+(x3-m)2+(x4-m)2+...(xN-m)2))/N)0.5
```

where `xi` is the ith element of the array

5. Lower and Upper Boundary of the `95%` **Confidence Interval** for the mean, separated by a space. This might be a new term to some. However, it is an important concept with a simple, formulaic solution. Look it up!

Other than the modal values (which should all be integers) the answers should be in decimal form till one place of decimal (0.0 format). An error margin of +/- 0.1 will be tolerated for the standard deviation and the confidence interval boundaries. The mean, mode and median values should match the expected answers exactly.

Assume that these numbers were sampled from a normal distribution; the sample is a reasonable representation of the distribution; a user can approximate that the population standard deviation =~ standard deviation computed for the given points- with the understanding that assumptions of normality are convenient approximations. Some relevant Youtube videos:


## Mean, Median and Mode

[![Watch the video](https://img.youtube.com/vi/5C9LBF3b65s/hqdefault.jpg)](https://youtu.be/5C9LBF3b65s)


## Standard Deviation


[![Watch the video](https://img.youtube.com/vi/dq_D30kyR1A/hqdefault.jpg)](https://youtu.be/dq_D30kyR1A)


## Confidence Intervals: Getting a bit more serious!


[![Watch the video](https://img.youtube.com/vi/tFWsuO9f74o/hqdefault.jpg)](https://youtu.be/tFWsuO9f74o)


## Input Format

The first line contains the number of integers.
The second line contains space separated integers for which you need to find the mean, median, mode, standard deviation and confidence interval boundaries.

## Constraints

```
10 <= N <= 2500
0 < xi <= 105
```

## Output Format

A total of five lines are required.

```
Mean (format:0.0) on the first line
Median (format: 0.0) on the second line
Mode(s) (Numerically smallest Integer in case of multiple integers)
Standard Deviation (format:0.0) 
Lower and Upper Boundary of Confidence Interval (format: 0.0) with a space between them.
```

## Sample Input

```
10
64630 11735 14216 99233 14470 4978 73429 38120 51135 67060
```

## Sample Output

```
43900.6
44627.5
4978
30466.9
25017.0 62784.2
```

## Note

Use the constant `1.96` while computing the confidence interval.

## Scoring

Scoring is proportional to the number of test cases cleared.

## Source

Hackerrank - [Basic Statistics Warmup](https://www.hackerrank.com/challenges/stat-warmup/problem)
