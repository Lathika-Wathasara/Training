#!/bin/python3

import math
import os
import random
import re
import sys
import heapq

#
# Complete the 'shop' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. STRING_ARRAY centers
#  4. 2D_INTEGER_ARRAY roads
#

def shop(n, k, centers, roads):
    f_masks = [0]
    all_f_masks = (2**k) - 1
    f = 1
    for i in range(k):
        f_masks.append(f)
        f *= 2
    cities = [0] * (n + 1)
    for idx, city_str in enumerate(centers):
        c_data = list(map(int, city_str.split()))
        if c_data[0] > 0:
            cities[idx + 1] = sum([f_masks[i] for i in c_data[1:]])
    times = [[0] * (n+1) for i in range(n+1)]       
    neighbours = [[] for _ in range(n+1)]
    for x1, x2, y in roads:
        neighbours[x1].append(x2)
        neighbours[x2].append(x1)
        times[x1][x2] = y
        times[x2][x1] = y
        
    P = [(1024) + cities[1]]
    S = [[False] * (all_f_masks + 1) for i in range(n + 1)]
    time_of_trip = [[None] * (all_f_masks + 1) for i in range(n + 1)]
    fmask = (2 ** 10) - 1
    nmask = fmask * 1024
    
    while P:
        D = heapq.heappop(P)
        time = D >> 20
        node = (D & nmask) >> 10
        f_mask = D & fmask
        if S[node][f_mask]:
            continue
        S[node][f_mask] = True
        if (node == n) and (f_mask == all_f_masks):
            continue
        for next in neighbours[node]:
            next_m_mask = cities[next] | f_mask
            if S[next][next_m_mask]:
                continue
            next_c_time = time_of_trip[next][next_m_mask]
            next_n_time = time + times[node][next]
            if (next_c_time is not None) and (next_n_time >= next_c_time):
                continue
            time_of_trip[next][next_m_mask] = next_n_time
            heapq.heappush(P, (next_n_time * 2**20) + (next * 2**10) + next_m_mask)
    R = 0
    time_of_trip = time_of_trip[n]
    for m_i, t_i in enumerate(time_of_trip):
        if not t_i:
            continue
        for d_j, t_j in enumerate(time_of_trip[m_i:]):
            if not t_j:
                continue
            m_j = m_i + d_j
            m = m_i | m_j
            total_time = max(t_i, t_j)
            if m!=all_f_masks:
                continue
            if R and total_time >= R:
                continue
            R = total_time
    return R

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    k = int(first_multiple_input[2])

    centers = []

    for _ in range(n):
        centers_item = input()
        centers.append(centers_item)

    roads = []

    for _ in range(m):
        roads.append(list(map(int, input().rstrip().split())))

    res = shop(n, k, centers, roads)

    fptr.write(str(res) + '\n')

    fptr.close()