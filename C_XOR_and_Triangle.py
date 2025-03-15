t = int(input().strip())
for _ in range(t):
    x = int(input().strip())
    ans = -1
    for i in range(31):
        if (x >> i) & 1:
            for q in range(i):
                if ((x >> q) & 1) == 0:
                    y = x - (1 << i) + (1 << q)
                    if (x & y) != 0 and (y & (~x)) != 0:
                        ans = y
                        break
            if ans != -1:
                break
    print(ans)
