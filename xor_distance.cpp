#include<iostream>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;
    ll a;
    while (cin >> a){
        ll b, c;
        if (a < b) {
            swap(a, b);
        }
        ll ans = a-b;
        ll cnt = 0;
        ll temp = ans;
        for (int i{60}; i>=0; i--){
            if (((b >>i)&1) == 0 and ((a >> i)&1) == 1 and cnt+(1LL << i) <= c){
                if (ans >= 2*(1LL << i)){
                    cnt += (1LL << i); 
                    ans -= 2*(1LL << i);
                }
                else {
                    temp = min(temp, 2*(1LL << i)-ans);
                }
            }
        }
        cout << min(ans, temp) << endl;
    }
}