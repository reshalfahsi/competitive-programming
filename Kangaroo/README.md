# Kangaroo

You are choreographing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).

* The first kangaroo starts at location *x*<sub>1</sub> and moves at a rate of *v*<sub>1</sub> meters per jump.
* The second kangaroo starts at location *x*<sub>2</sub> and moves at a rate of *v*<sub>2</sub> meters per jump.

You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. If it is possible, return YES, otherwise return NO.

For example, kangaroo *1* starts at *x*<sub>1</sub> = *2* with a jump distance *v*<sub>1</sub> = *1* and kangaroo *2* starts at *x*<sub>2</sub> = *1* with a jump distance of *v*<sub>2</sub> = *2*. After one jump, they are both at *x* = *3*, (*x*<sub>1</sub> + *v*<sub>1</sub> = *2* + *1*, *x*<sub>2</sub> + *v*<sub>2</sub> = *1* + *2*), so our answer is YES.

### Function Description
Complete the function kangaroo in the editor below. It should return YES if they reach the same position at the same time, or NO if they don't.

kangaroo has the following parameter(s):

* *x*<sub>1</sub>, *v*<sub>1</sub>: integers, starting position and jump distance for kangaroo *1*
* *x*<sub>2</sub>, *v*<sub>2</sub>: integers, starting position and jump distance for kangaroo *2* 

### Input Format

A single line of four space-separated integers denoting the respective values of *x*<sub>1</sub>, *x*<sub>2</sub>, *v*<sub>1</sub>, and *v*<sub>2</sub>

### Constraints

* *0* <ins><</ins> *x*<sub>1</sub> *<* *x*<sub>2</sub> <ins><</ins> *10000*
* *1* <ins><</ins> *v*<sub>1</sub> <ins><</ins> *10000*
* *1* <ins><</ins> *v*<sub>2</sub> <ins><</ins> *10000*

### Output Format

Print YES if they can land on the same location at the same time; otherwise, print NO.

**Note:** The two kangaroos must land at the same location after making the same number of jumps.

### Sample Input 0

~~~
0 3 4 2
~~~

### Sample Output 0

~~~
YES
~~~

### Explanation 0

The two kangaroos jump through the following sequence of locations:

![alt text](kangaroo_jump.png)

From the image, it is clear that the kangaroos meet at the same location (number *12* on the number line) after same number of jumps (*4* jumps), and we print YES.

### Sample Input 1

~~~
0 2 5 3
~~~

### Sample Output 1

~~~
NO
~~~

### Explanation 1

The second kangaroo has a starting location that is ahead (further to the right) of the first kangaroo's starting location (i.e., *x*<sub>2</sub>> *x*<sub>1</sub>). Because the second kangaroo moves at a faster rate (meaning *v*<sub>2</sub> > *v*<sub>1</sub>) and is already ahead of the first kangaroo, the first kangaroo will never be able to catch up. Thus, we print NO.

### Hint

Count the difference every timestep, if convergence then they will meet at somepoint but if getting bigger then they will never meet ~~like you and your highschool crush~~!

### Source

Hackerrank [Kangaroo](https://www.hackerrank.com/challenges/kangaroo/problem)

Credits to [Okta Fajar Suryani](https://github.com/Oktafsurya)
