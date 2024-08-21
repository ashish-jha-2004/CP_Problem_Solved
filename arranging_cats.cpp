#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i{0}; i<t; i++){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<bool> fix(n, false);
        for (int j{0}; j<n; j++){
            if (a[j] == b[j]){
                fix[j] = true;
            }
        }
        int cnt = 0;
        for (int j{0}; j<n; j++){
            if (!fix[j]){
                cnt++;
            }
        }
        int turn = 0;
        int no_of_nfixed_one_ina{0}, no_of_nfixed_one_inb{0};
        for (int j{0}; j<n; j++){
            if (a[j] == '1' and !fix[j]){
                no_of_nfixed_one_ina++;
            }
            if (b[j] == '1' and !fix[j]){
                no_of_nfixed_one_inb++;
            }
        }
        turn = min(no_of_nfixed_one_ina, no_of_nfixed_one_inb);
        cnt -= turn*2;
        turn += cnt;
        cout << turn <<endl;
    }
}