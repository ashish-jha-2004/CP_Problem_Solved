#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct Res {
    ll leftMult, leftAdd, rightMult, rightAdd;
};
 
vector<Res> dp;
vector<bool> computed;

Res rec(int i, int n, const vector<char> &opL, const vector<ll> &valL,
        const vector<char> &opR, const vector<ll> &valR) {
    if(i == n) {
        // Base case: no more gates.
        return {1, 0, 1, 0};
    }
    if(computed[i])
        return dp[i];
    
    Res next = rec(i+1, n, opL, valL, opR, valR);
    Res cur;
    
    if(opL[i] == '+'){
        cur.leftMult = next.leftMult;
        cur.leftAdd = next.leftAdd + valL[i] * max(next.leftMult, next.rightMult);

    } 
    else if(opL[i] == 'x'){
        cur.leftMult = next.leftMult + (valL[i] - 1) * max(next.leftMult, next.rightMult);
        cur.leftAdd = next.leftAdd;
    }

    if(opR[i] == '+'){
        cur.rightMult = next.rightMult;
        cur.rightAdd = next.rightAdd + valR[i] * max(next.leftMult, next.rightMult);
    } else if(opR[i] == 'x'){
        cur.rightMult = next.rightMult + (valR[i] - 1) * max(next.leftMult, next.rightMult);
        cur.rightAdd = next.rightAdd;
    }
    
    dp[i] = cur;
    computed[i] = true;
    return cur;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> opL(n), opR(n);
        vector<ll> valL(n), valR(n);
 
        for (int i = 0; i < n; i++){
            cin >> opL[i] >> valL[i] >> opR[i] >> valR[i];
        }
 
        // Prepare memoization arrays.
        dp.assign(n+1, {0,0,0,0});
        computed.assign(n+1, false);
 
        // Base case for memoization at index n.
        dp[n] = {1, 0, 1, 0};
        computed[n] = true;
 
        // Compute the DP result recursively.
        Res res = rec(0, n, opL, valL, opR, valR);
 
        ll left_total = 1 * res.leftMult + res.leftAdd;
        ll right_total = 1 * res.rightMult + res.rightAdd;
        cout << (left_total + right_total) << "\n";
    }
    return 0;
}
