#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/*
****************************************************************************************************************************************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
****************************************************************************************************************************************************************************************************************************************************************************
    मनोबुद्ध्यहङ्कारचित्तानि नाहं न च श्रोत्रजिह्वे न च घ्राणनेत्रे ।
    न च व्योम भूमिर्न तेजो न वायुश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥१॥
    
    न च प्राणसंज्ञो न वै पञ्चवायुर्न वा सप्तधातुर्न वा पञ्चकोशाः ।
    न वाक्पाणिपादं न चोपस्थपायुश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥२॥
    
    न मे द्वेषरागौ न मे लोभमोहौ मदो नैव मे नैव मात्सर्यभावः ।
    न धर्मो न चार्थो न कामो न मोक्षश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥३॥
    
    न पुण्यं न पापं न सौख्यं न दुःखं न मन्त्रो न तीर्थं न वेदा न यज्ञाः ।
    अहं भोजनं नैव भोज्यं न भोक्ता चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥४॥  
    
    न मृत्युर्न शङ्का न मे जातिभेदः पिता नैव मे नैव माता न जन्म ।
    न बन्धुर्न मित्रं गुरुर्नैव शिष्यश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥५॥
    
    अहं निर्विकल्पो निराकाररूपो विभुत्वाञ्च सर्वत्र सर्वेन्द्रियाणाम् ।
    न चासङ्गतं नैव मुक्तिर्न मेयश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥६॥
****************************************************************************************************************************************************************************************************************************************************************************
*/

// Debugging Tools For CP
#ifndef ONLINE_JUDGE
#include <debugtemplate.hpp>
#else
#define debug(...)
#endif

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef pair<ll, ll> pll;
typedef pair<ll, char> plc;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fb(i, j, k) for (int i{j}; i>=k; i--)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFINE_AND_READ(type, ...) type __VA_ARGS__; read(__VA_ARGS__)
#define d_n(...) DEFINE_AND_READ(ll, __VA_ARGS__)
#define d_s(...) DEFINE_AND_READ(string, __VA_ARGS__)
#define d_c(...) DEFINE_AND_READ(char, __VA_ARGS__)
#define d_d(...) DEFINE_AND_READ(ld, __VA_ARGS__)
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i]
#define en "\n"
#define F first
#define S second
#define PB push_back
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

// Utility Function
template <class T> 
using ind_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T>
void pt(T &&t)  { cout << t << "\n"; }
template<typename T>
ll sv(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
template<typename... T>
void read(T&... args) {
    (cin >> ... >> args);
}

// Number Theory
const ll MOD = 1e9+7, mod = MOD;
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll modpow(ll x, ll n, int m = MOD){if (x == 0 && n == 0) return 0; ll res = 1; while (n > 0){ if (n % 2) res = (res * x) % m; x = (x * x) % m; n /= 2; } return res; }
int modinv(int x, int m = MOD) { return modpow(x, m - 2, m);}
ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }
ll factorial(ll n){if (n==0){ return 1;} ll ans=1;for (ll i=1;i<=n;i++) { ans=mod_mul(ans,i); } return ans; }
ll nCr(ll n, ll r) { if (n<r){ return 0;} ll ans=factorial(n); ans=mod_mul(ans,inv(factorial(r))); ans=mod_mul(ans,inv(factorial(n-r))); return ans; }

set<ll> visited_G;
set<ll> visited_F;
set<ll> already_stored;
ll cnt = 0;


void make_set(vector<int>& parent, vector<int>& rank, int n) {
    parent.resize(n + 1);
    rank.assign(n + 1, 0);
    for (int i = 0; i < n + 1; ++i)
        parent[i] = i;
}

int find_set(vector<int>& parent, int v) {
    if (v != parent[v])
        parent[v] = find_set(parent, parent[v]);
    return parent[v];
}

void union_sets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void dfs3(vector<set<ll>> &graph_F_1, vector<set<ll>> &graph_F, ll node, vector<int> &parent) {
    if (visited_F.count(node) != 0) return;
    visited_F.insert(node);
    
    for (auto nbr: graph_F_1[node]) {
        if (find_set(parent, nbr) != find_set(parent, node)) {
            // this means there is no path from ndr to parent in G
            if (graph_F[node].count(nbr) != 0) {
                graph_F[node].erase(nbr);
                graph_F[nbr].erase(node);
                cnt += 1;
            }
        }
        dfs3(graph_F_1, graph_F, nbr, parent);
    }
}

void dfs2(vector<set<ll>> &graph_G, ll node, vector<int> &parent, vector<int> &rank) {
    if (visited_G.count(node) != 0) return;
    visited_G.insert(node);
    for (auto nbr: graph_G[node]){
        union_sets(parent, rank, nbr, node);
        dfs2(graph_G, nbr, parent, rank);
    }
}

void dfs1(vector<set<ll>> &graph_F, ll node) {
    if (visited_F.count(node) != 0) return;
    visited_F.insert(node);
    already_stored.insert(node);
    for (auto nbr: graph_F[node]) {
        dfs1(graph_F, nbr);
    }
}

void dfs(vector<set<ll>> &graph_F, vector<set<ll>> &graph_G, ll node) {
    if (visited_G.count(node) != 0) return;
    visited_G.insert(node);
    dfs1(graph_F, node);
    // if (cnt != 1) debug(node, visited_F, graph_F);
    for (auto nbr: graph_G[node]){
        if (graph_F[node].count(nbr) == 0 and already_stored.count(nbr) == 0) {
            graph_F[node].insert(nbr);
            graph_F[nbr].insert(node);
            already_stored.insert(nbr);
            cnt += 1;
        }
        dfs(graph_F, graph_G, nbr);
    }
}

void solve(){
    // code here
    d_n(n, m1, m2);

    if (m1 == 0 and m2 == 0) {
        cout << 0 << en;
        return;
    }
    // making graph
    vector<set<ll>> graph_F(n + 1);
    vector<set<ll>> graph_F_1(n + 1);
    vector<set<ll>> graph_G(n + 1);
    fl(i, m1) {
        d_n(x, y);
        graph_F[x].insert(y);
        graph_F[y].insert(x);
        graph_F_1[x].insert(y);
        graph_F_1[y].insert(x);
    }
    fl(i, m2) {
        d_n(x, y);
        graph_G[x].insert(y);
        graph_G[y].insert(x);
    }
    vector<int> parent, rank;
    make_set(parent, rank, n);
    // deleting some edges which are not the connected component of G in F
    fn(i, 1, n + 1) {
        if (visited_G.count(i) == 0) {
            dfs2(graph_G, i, parent, rank);
        }
    }
    visited_G.clear();
    fn(i, 1, n + 1) {
        if (visited_F.count(i) == 0) {
            dfs3(graph_F_1, graph_F, i, parent);
        }
    }
    visited_F.clear();
    debug(graph_F);

    // modifying F to be atleast connected as G
    fn(i, 1, n + 1) {
        if (visited_G.count(i) == 0) {
            dfs(graph_F, graph_G, i);
        }
    }
    cout << cnt << en;
    debug(cnt);
    visited_F.clear();
    visited_G.clear();
    already_stored.clear();
    cnt = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--){
        solve();
    }
    return 0;
}