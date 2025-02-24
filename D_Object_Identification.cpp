#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
    cout << "? " << i << " " << j << "\n" << flush;
    int resp;
    cin >> resp;
    if(resp == -1) exit(0);
    return resp;
}

string solveCase(int n, const vector<int>& arr) {
    // Mark which numbers in [1, n] appear.
    vector<bool> present(n+1, false);
    for (int i = 1; i <= n; i++) {
        if(arr[i] >= 1 && arr[i] <= n)
            present[arr[i]] = true;
    }
    
    // Look for a missing number.
    int candidate = -1;
    for (int v = 1; v <= n; v++) {
        if(!present[v]) {
            candidate = v;
            break;
        }
    }
    
    // If there's a missing number, make one query.
    if(candidate != -1) {
        int other = (candidate == 1 ? 2 : 1);
        int resp = query(candidate, other);
        return (resp == 0 ? "A" : "B");
    }
    
    // Otherwise, all numbers appear.
    // Find indices with minimum and maximum values.
    int idxMin = 1, idxMax = 1;
    for (int i = 1; i <= n; i++) {
        if(arr[i] < arr[idxMin])
            idxMin = i;
        if(arr[i] > arr[idxMax])
            idxMax = i;
    }
    int diff = abs(arr[idxMin] - arr[idxMax]);
    
    int r = query(idxMin, idxMax);
    if(r < diff)
        return "A";
    else if(r > diff)
        return "B";
    else {
        int r2 = query(idxMax, idxMin);
        return (r2 == diff ? "B" : "A");
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        if(!(cin >> n)) return 0;
        vector<int> arr(n+1);
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        string answer = solveCase(n, arr);
        cout << "! " << answer << "\n" << endl;
    }
    return 0;
}
