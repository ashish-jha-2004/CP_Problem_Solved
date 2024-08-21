#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

#define int long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define PI 3.14159

void solve(int n){
    vector<int> v;
    fl(i, n){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int sum = 0;
    fl(i, n){
        sum += v[i];
    }
    double ans1 = sqrt(sum);
    int ans2 = ans1/1;
    if (ans1-ans2 == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

main(){
    int t;
    cin >> t;
    int n;
    while (cin >> n){
        solve(n);
    }
}