#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

bool is_in1(ll rem, int m){
    if (rem == 1 || rem == 3 || rem == 6 || rem == 10 || ((rem == 5)&&(rem != m))) return true;
    return false;
}

bool is_in2(ll rem, int m){
    if (rem == 2 || rem == 7 || rem == 9 || ((rem == 8)&&(rem != m)) || rem == 11 || rem == 13 || rem == 12 || rem == 4) return true;
    return false;
}

int finding(ll &rem, int m){
    if (rem == 0){
        return 0;
    }
    else if (is_in1(rem, m)){
        return 1;
    }
    else if (is_in2(rem, m)){
        return 2;
    }
    else {
        return 3;
    }
}

ll is_possible(std::vector<int> &vec, ll &n, int m){
    ll maxi = 100000000000000, ans;
    for (int i{4}; i>=0; --i){
        ll rem = n%vec[i];
        ans = n/vec[i];
        ans += finding(rem, m);
        maxi = std::min(ans, maxi);
        ans = 0;
    }
    return maxi;
}

void solve(){
    // code here
    ll n;
    std::cin >> n;
    std::vector<int> vec{1, 3, 6, 10, 15};
    int m = n;
    if (n >= 15){
        std::cout << is_possible(vec, n, m) << std::endl;
    }
    else {
        std::cout << finding(n, m) << std::endl;
    }
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