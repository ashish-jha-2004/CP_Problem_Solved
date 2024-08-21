#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;
    bool isOr;

    void build(const vector<long long>& arr, int node, int start, int end, bool isOr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid, !isOr);
            build(arr, 2 * node + 2, mid + 1, end, !isOr);
            if (isOr)
                tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
            else
                tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
        }
    }

    void update(int node, int start, int end, int idx, long long val, bool isOr) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, val, !isOr);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val, !isOr);
            }
            if (isOr)
                tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
            else
                tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        int height = ceil(log2(n));
        isOr = height % 2 == 1;
        build(arr, 0, 0, n - 1, isOr);
    }

    void update(int idx, long long val) {
        update(0, 0, n - 1, idx, val, isOr);
    }

    long long query() {
        return tree[0];
    }
};

// Implementing that
int main() {
    int n, m;
    cin >> n >> m;
    int size = 1 << n;
    vector<long long> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    SegmentTree segTree(a);

    while (m--) {
        int p;
        long long b;
        cin >> p >> b;
        segTree.update(p - 1, b);
        cout << segTree.query() << endl;
    }

    return 0;
}
