#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i{0}; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int mark = v[k-1];
    int cnt = 0;
    for (int i{0}; i<n; i++){
        if (v[i] != 0 and v[i] >= mark){
            cnt++;
        }
        else {
            break;
        }
    }
    cout << cnt;
}