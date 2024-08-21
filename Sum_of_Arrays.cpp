#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fb(i, j, k) for (int i{j}; i>=k; i--)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define d_n(n) ll n; cin >> n
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
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}

// Mathematical Function
ll gcd(ll a, ll b){
    if (b == 0)return a;
    return gcd(b, a % b);
} 
ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}
string decToBinary(int n){
    string s="";
    int i = 0;
    while (n > 0) {
        s =to_string(n % 2)+s;
        n = n / 2;
        i++;
    }return s;
}
ll binaryToDecimal(string n){
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for(int i = len - 1; i >= 0; i--){
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(ll n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i<=n; i+=6)
        if(n%i == 0 || n%(i + 2) == 0) return false;
    return true;
}
bool isPowerOfTwo(ll n){
    if(n == 0)return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x){
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

void solve(){
    // code here
    d_n(n1);
    d_v(v1, n1);
    d_n(n2);
    d_v(v2, n2);
    ll num1 = 0;
    int k = 1;
    fb(i, n1-1, 0){
        num1 += k*v1[i];
        k = k*10;
    }
    k = 1;
    ll num2 = 0;
    fb(i, n1-1, 0){
        num2 += k*v2[i];
        k = k*10;
    }
    // cerr << num1 << " " << num2;
    ll sum = num1 + num2;
    // cerr << " " << sum ;
    string so = to_string(sum);
    cout << 1 << en;
    fl(i, so.size()){
        cout << so[i] << en;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}