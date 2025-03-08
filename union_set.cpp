#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void make_set(vector<int>& parent, vector<int>& rank, int n) {
    parent.resize(n);
    rank.assign(n, 0);
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}

int find_set(vector<int>& parent, int v) {
    if (v != parent[v])
        parent[v] = find_set(parent, parent[v]);
    return parent[v];
}

void union_sets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int n = 10;  // Number of elements
    vector<int> parent, rank;
    make_set(parent, rank, n);

    // Example unions
    union_sets(parent, rank, 2, 3);
    union_sets(parent, rank, 3, 4);
    union_sets(parent, rank, 1, 2);
    union_sets(parent, rank, 5, 6);
    union_sets(parent, rank, 7, 8);
    union_sets(parent, rank, 8, 9);

    // Display the representative of each element
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i << " belongs to set with representative " 
             << find_set(parent, i) << "\n";
    }

    return 0;
}
