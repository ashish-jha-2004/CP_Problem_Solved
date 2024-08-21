#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long n;
    while (cin >> n){
        vector<long long> a(n, 0);
        vector<long long> b(n, 0);
        for (long long i{0}; i<n; i++){
            cin >> a[i];
        }
        for (long long i{0}; i<n; i++){
            cin >> b[i];
        }
        unordered_map<long long, long long> m;
        for (long long s{0}; s<n; s++){
            m[a[s]] = b[s];
        }
        sort(a.begin(), a.end());
        for (auto i: a){
            cout << i << " ";
        }
        cout << endl;
        for (long long i{0}; i<n; i++){
            cout << m[a[i]] << " ";
        }
        cout <<endl;
    }
}