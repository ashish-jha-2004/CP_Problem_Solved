import sys, math
from collections import defaultdict
input = sys.stdin.readline

t = int(input().strip())
results = []
for _ in range(t):
    n, m = map(int, input().split())
    centers = list(map(int, input().split()))
    radii = list(map(int, input().split()))
    intervals_by_y = defaultdict(list)
    for i in range(n):
        x = centers[i]
        r = radii[i]
        r2 = r * r
        for y in range(-r, r + 1):
            rem = r2 - y * y
            if rem < 0:
                continue
            dx = math.isqrt(rem)
            L = x - dx
            R = x + dx
            intervals_by_y[y].append((L, R))
    total_points = 0
    for y, intervals in intervals_by_y.items():
        intervals.sort(key=lambda interval: interval[0])
        merged = []
        curL, curR = intervals[0]
        for L, R in intervals[1:]:
            if L <= curR + 1:
                curR = max(curR, R)
            else:
                merged.append((curL, curR))
                curL, curR = L, R
        merged.append((curL, curR))
        for L, R in merged:
            total_points += (R - L + 1)
    results.append(str(total_points))
sys.stdout.write("\n".join(results))
