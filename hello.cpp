#include<iostream>
#include<vector>
#include<string>
using namespace std;
    
int main(){
    int t;
    cin >> t;
    for (int i{0}; i<t; i++){
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        int j{0};
        int cnt = 0;
        for (; j<n; j++){
            if (a[j] == c[j] || b[j] == c[j]){
                cnt++;
            }
        }
        if (n == 1){
            if (a[0] == c[0] || b[0] == c[0]){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
        else if (cnt >= n){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}