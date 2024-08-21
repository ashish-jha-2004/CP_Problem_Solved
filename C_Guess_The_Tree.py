import sys
input = sys.stdin.read

def query(a, b):
    print(f"? {a} {b}")
    sys.stdout.flush()
    return int(input().strip())

def solve(a, b, vis, edges):
    x = query(a, b)
    if x == a or x == b:
        edges.append((a, b))
        vis[x] = vis[b] = 1
    else:
        if vis[a] and vis[x]:
            solve(x, b, vis, edges)
        else:
            solve(a, x, vis, edges)
            solve(x, b, vis, edges)

def main():
    data = input().split()
    index = 0
    t = int(data[index])
    index += 1
    results = []

    for _ in range(t):
        n = int(data[index])
        index += 1
        if n != 2:
            results.append("! 1 2")
            continue

        vis = [0] * (n + 1)
        edges = []

        for i in range(1, n):
            for j in range(i + 1, n + 1):
                if not vis[j]:
                    solve(i, j, vis, edges)
        
        results.append("!" + " ".join(f" {x[0]} {x[1]}" for x in edges))
    
    print("\n".join(results))
    sys.stdout.flush()

if __name__ == "__main__":
    main()
