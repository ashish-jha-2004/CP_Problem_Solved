#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i{0}; i<t; i++){
        int n;
        long long f, a, b;
        cin >> n >> f >> a >> b;
        vector<int> m(n+1, 0);
        for (int j{1}; j<n+1; j++){
            cin >> m[j];
        }
        int b_bal = f;
        for (int j{1}; j<n+1; j++){
            if ((m[j] - m[j-1])*a <= b){
                b_bal -= (m[j] - m[j-1])*a; 
            }
            if ((m[j] - m[j-1])*a > b){
                b_bal -= b;
            }
            if (b_bal <= 0){
                cout << "NO" << endl;
                break;
            }
        }
        if (b_bal > 0){
            cout << "YES" << endl;
        }
    }
}