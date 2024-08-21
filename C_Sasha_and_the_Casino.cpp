#include<iostream>
using namespace std;
#define ll long long


ll next_bet(ll cur_loss, ll k){
    return (cur_loss + k - 1)/ (k - 1);
}

int main(){
    int t;
    cin >> t;

    while (t--){
        ll k, x, a;
        cin >> k >> x >> a;
        ll uttar = 0;
        int ok = 1;
        for (int i{0}; ok && i < x; i++){
            ll v = next_bet(uttar, k);
            uttar += (v == 0) ? 1 : v;
            ok = (uttar <= a);
        }

        (k * (a - uttar) > a) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
