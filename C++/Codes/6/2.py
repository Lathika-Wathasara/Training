#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'prims' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY edges
#  3. INTEGER start
#



def prims(n, edges, start):
    graph=[[] for i in range(n+1)]
    for x in range(len(edges)):
        a,b,c = edges[x]
        graph[a].append((b, c))
        graph[b].append((a, c)) 
    s = {i + 1 for i in range(n)}
    t = set()
    Total = 0
    t.add(s.pop())
    while s:
        min_start = -1;
        min_end = -1;
        min_weight = float("inf");
        for v in t:
            for e in graph[v]:            
                if e[0] in s:
                    if e[1] < min_weight:
                        min_start = v
                        min_end = e[0]
                        min_weight = e[1] 
        if min_weight < float("inf"):
            Total += min_weight
            s.remove(min_end)
            t.add(min_end)
            
    return Total
        
   

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    edges = []

    for _ in range(m):
        edges.append(list(map(int, input().rstrip().split())))

    start = int(input().strip())

    result = prims(n, edges, start)

    fptr.write(str(result) + '\n')

    fptr.close()