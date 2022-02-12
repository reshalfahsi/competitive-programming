import math
import os
import random
import re
import sys

# Complete the kangaroo function below.
def kangaroo(x1, v1, x2, v2):
    last_delta = 999999
    if x1 == x2:
        result = str('YES')
        return result
    i = 1
    while(True):
        k1Pos = x1 + i*v1
        k2Pos = x2 + i*v2
        i += 1
        if k1Pos == k2Pos:
            result = str('YES')
            break
        if(last_delta>abs(k1Pos-k2Pos)):
            last_delta = abs(k1Pos-k2Pos)
            continue
        else:
            result = str('NO')
            break
    return result

if __name__ == '__main__':
    
    x1V1X2V2 = input().split()
    
    x1 = int(x1V1X2V2[0])
    v1 = int(x1V1X2V2[1])
    x2 = int(x1V1X2V2[2])
    v2 = int(x1V1X2V2[3])

    result = kangaroo(x1, v1, x2, v2)

    print(result)
