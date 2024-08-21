#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define ll long long
#define floop(i, j) for(int i{0}; i<j; i++)
#define PI 3.14159

void solve(int n){
    int k;
    cin >> k;
    vector<int> b;
    floop(i, n){
        int x;
        cin >> x;
        b.push_back(x);
    }
    ll product = 1;
    floop(i, n){
        product *= b[i];
    }
    if (product > 2023) {
        cout << "NO\n";
    }
    else{
        if (2023%product != 0){
            cout << "NO\n";
        }
        else if (2023%product == 0){
            ll temp = 2023/product;
            cout << "YES\n";
            cout << temp << " ";
            k = k - 1;
            floop(i, k){
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    int n;
    while (cin >> n){
        solve(n);
    }
}