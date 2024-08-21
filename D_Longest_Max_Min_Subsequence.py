def solve():
    n = int(input())
    seq = list(map(int, input().split()))
    
    pos = [-1] * (n + 1)
    count = [0] * (n + 1)
    visited = [False] * (n + 1)
    indices = [[] for _ in range(n + 1)]

    min_pos = float('inf')
    
    for i in range(1, n + 1):
        pos[seq[i-1]] = i
        indices[seq[i-1]].append(i)

    for i in range(1, n + 1):
        if pos[i] != -1:
            count[pos[i]] += 1
            min_pos = min(min_pos, pos[i])

    result = []
    idx = 1
    
    while idx <= n:
        if idx == min_pos:
            result.append(seq[idx-1])
            count[pos[seq[idx-1]]] -= 1
            while min_pos <= n and count[min_pos] == 0:
                min_pos += 1
            idx += 1
        else:
            if len(result) & 1:
                min_val = float('inf')
                for j in range(idx, min(min_pos, n) + 1):
                    if not visited[j]:
                        min_val = min(min_val, seq[j-1])
                for j in range(idx, min(min_pos, n) + 1):
                    if seq[j-1] == min_val:
                        idx = j + 1
                        break
                if min_val == float('inf'):
                    break
                result.append(min_val)
                count[pos[min_val]] -= 1
                while min_pos <= n and count[min_pos] == 0:
                    min_pos += 1
            else:
                max_val = 0
                for j in range(idx, min(min_pos, n) + 1):
                    if not visited[j]:
                        max_val = max(max_val, seq[j-1])
                for j in range(idx, min(min_pos, n) + 1):
                    if seq[j-1] == max_val:
                        idx = j + 1
                        break
                if max_val == 0:
                    break
                result.append(max_val)
                count[pos[max_val]] -= 1
                while min_pos <= n and count[min_pos] == 0:
                    min_pos += 1

        for i in indices[result[-1]]:
            visited[i] = True

    print(len(result))
    print(' '.join(map(str, result)))

T = int(input())
for _ in range(T):
    solve()
