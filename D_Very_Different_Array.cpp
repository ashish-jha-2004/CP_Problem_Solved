#include<bits/stdc++.h>
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> vn(n), vm(m);
    fl(i, n) std::cin >> vn[i];
    fl(i, m) std::cin >> vm[i];
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    reverse(vm.begin(), vm.end());
    ll ptr1{0}, ptr2{n-1}, ptr3{0}, ptr4{m-1}, ans = 0;
    while (ptr1 <= ptr2){
        if (abs(vn[ptr1] - vm[ptr3]) > abs(vn[ptr2] - vm[ptr4])){
            ans += abs(vn[ptr1] - vm[ptr3]);
            ptr1++;
            ptr3++;
        }
        else {
            ans += abs(vn[ptr2] - vm[ptr4]);
            ptr2--;
            ptr4--;
        }
    }
    std::cout << ans << std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--){
        solve();
    }
    return 0;
}