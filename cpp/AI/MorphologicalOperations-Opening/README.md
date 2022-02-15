# Morphological Operations: Opening

You are provided the following image `B`

```
0000000000
0111111100
0000111100
0000111100
0001111100
0000111100
0001100000
0000000000
0000000000
```

The structuring element `S` is given below, and its' origin is the middle pixel.

```
111
111
111
```

What is the **total number of pixels marked 1** in the image obtained after `B` is opened with the structuring element `S`? Only enter the integer, or a program to compute it.

## Hint

[Opening](https://en.wikipedia.org/wiki/Opening_(morphology)) is [Erosion](https://en.wikipedia.org/wiki/Erosion_(morphology)) followed by [Dilation](https://en.wikipedia.org/wiki/Dilation_(morphology)).

## Source

Hackerrank - [Morphological Operations: Opening](https://www.hackerrank.com/challenges/dip-morphological-operations-opening/problem)
