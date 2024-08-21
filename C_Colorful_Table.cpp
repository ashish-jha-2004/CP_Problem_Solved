#include <bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define forn(i, x, n) for (int i = x; i < n; i++)

#define vi vector<int>

#define vpp vector<pair<int,int>>

#define vs vector<string>

#define vll vector<long long>

#define ss second

#define ff first

int row[] = {1,0,-1,0};

int col[] = {0,1,0,-1};

const int mod = 1e9 + 7;


void solve(){  
    int n,k;
    cin>>n>>k;
    vi a(n);

    set<int> st;

    forn(i,0,n){

        cin>>a[i];

        st.insert(a[i]);

    }
    int s = 0;
    int e = n-1;
    for(int i=1; i<=k; i++){
        if(st.count(i) == 0) cout<<0<<' ';
        else{
            while(s <= e and a[s] < i) s++;
            while(e >= s and a[e] < i) e--;
            cout<<2*(abs(s-e)+1)<<' ';
        }
    }cout<<'\n';

}
signed main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
} 