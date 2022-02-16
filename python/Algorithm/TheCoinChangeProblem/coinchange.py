#!/bin/python3

import os

def getWays(n, c):
    # create dp table
    dp = [1] + [0] * n
    
    # solve using dynamic programming
    for coin in c: 
        for idx in range(coin, n + 1):
            dp[idx] += dp[idx - coin]
    
    return dp[n]


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    c = list(map(int, input().rstrip().split()))

    ways = getWays(n, c)

    fptr.write(str(ways) + '\n')

    fptr.close()
