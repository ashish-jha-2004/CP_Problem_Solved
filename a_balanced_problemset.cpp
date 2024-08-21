#include<iostream>
#include<cmath>
using namespace std;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin >> s;
    long long x;
    while (cin >> x){
        long long n;
        cin >> n;
        long long ans = 1;
        for (long long i{1}; i<=sqrt(x)/1+1; i++){
            if (x%i == 0){
                long long z = x/i;
                if (z >= n){
                    ans = max(ans, i);
                }
                if (i >= n){
                    ans = max(z, ans);
                }
            }
        }
        cout << ans << endl << endl;
    }
    return 0;
}