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
    यं यं यं यक्षरूपं दशदिशिविदितं भूमिकम्पायमानं, सं सं संहारमूर्तिं शिरमुकुटजटा शेखरंचन्द्रबिम्बम् ।, दं दं दं दीर्घकायं विक्रितनख मुखं चोर्ध्वरोमं करालं, पं पं पं पापनाशं प्रणमत सततं भैरवं क्षेत्रपालम् ॥ १॥
    रं रं रं रक्तवर्णं, कटिकटिततनुं तीक्ष्णदंष्ट्राकरालं, घं घं घं घोष घोषं घ घ घ घ घटितं घर्झरं घोरनादम् ।, कं कं कं कालपाशं द्रुक् द्रुक् दृढितं ज्वालितं कामदाहं, तं तं तं दिव्यदेहं, प्रणामत सततं, भैरवं क्षेत्रपालम् ॥ २॥
    लं लं लं लं वदन्तं ल ल ल ल ललितं दीर्घ जिह्वा करालं, धूं धूं धूं धूम्रवर्णं स्फुट विकटमुखं भास्करं भीमरूपम् ।, रुं रुं रुं रूण्डमालं, रवितमनियतं ताम्रनेत्रं करालम्, नं नं नं नग्नभूषं, प्रणमत सततं, भैरवं क्षेत्रपालम् ॥ ३॥
    वं वं वायुवेगं नतजनसदयं ब्रह्मसारं परन्तं, खं खं खड्गहस्तं त्रिभुवनविलयं भास्करं भीमरूपम् ।, चं चं चलित्वाऽचल चल चलिता चालितं भूमिचक्रं, मं मं मायि रूपं प्रणमत सततं भैरवं क्षेत्रपालम् ॥ ४॥
    शं शं शं शङ्खहस्तं, शशिकरधवलं, मोक्ष सम्पूर्ण तेजं, मं मं मं मं महान्तं, कुलमकुलकुलं मन्त्रगुप्तं सुनित्यम् ।, यं यं यं भूतनाथं, किलिकिलिकिलितं बालकेलिप्रदहानं, आं आं आं आन्तरिक्षं, प्रणमत सततं, भैरवं क्षेत्रपालम् ॥ ५॥
    खं खं खं खड्गभेदं, विषममृतमयं कालकालं करालं, क्षं क्षं क्षं क्षिप्रवेगं, दहदहदहनं, तप्तसन्दीप्यमानम् ।, हौं हौं हौंकारनादं, प्रकटितगहनं गर्जितैर्भूमिकम्पं, बं बं बं बाललीलं, प्रणमत सततं, भैरवं क्षेत्रपालम् ॥ ६॥
    वं वं वं वाललीलं, सं सं सं सिद्धियोगं, सकलगुणमखं, देवदेवं प्रसन्नं, पं पं पं पद्मनाभं, हरिहरमयनं चन्द्रसूर्याग्नि नेत्रम् ।, ऐं ऐं ऐं ऐश्वर्यनाथं, सततभयहरं, पूर्वदेवस्वरूपं, रौं रौं रौं रौद्ररूपं, प्रणमत सततं, भैरवं क्षेत्रपालम् ॥ ७॥
    हं हं हं हंसयानं, हसितकलहकं, मुक्तयोगाट्टहासं, धं धं धं नेत्ररूपं, शिरमुकुटजटाबन्ध बन्धाग्रहस्तम् ।, तं तं तंकानादं, त्रिदशलटलटं, कामगर्वापहारं, भ्रुं भ्रुं भ्रुं भूतनाथं, प्रणमत सततं, भैरवं क्षेत्रपालम् ॥ ८॥
    नमो भूतनाथं नमो प्रेतनाथं, नमः कालकालं नमः रुद्रमालम् ।, नमः कालिकाप्रेमलोलं करालं, नमो भैरवं काशिकाक्षेत्रपालम् ॥
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

char other(char a, char b) {
    if (a == b) return '?';
    if (a == 'L') {
        if (b == 'T') return 'I';
        else return 'T';
    }
    else if (a == 'T') {
        if (b == 'I') return 'L';
        else return 'I';
    }
    else {
        if (b == 'L') return 'T';
        else return 'L';
    }
}



char first_mini(map<char, int> char_cnt) {
    int mn = min(char_cnt['L'], min(char_cnt['T'], char_cnt['I']));
    for (auto &k: char_cnt) {
        if (k.S == mn) return k.F;
    }
}

char second_mini(map<char, int> char_cnt) {
    vector<int> kt;
    for (auto &k: char_cnt) {
        kt.push_back(k.S);
    }
    sort(all(kt));
    int mn = kt[1];
    for (auto &k: char_cnt) {
        if (k.S == mn and k.F != first_mini(char_cnt)) return k.F;
    }
}

void ins(string &s, int i, char ch) {
    string temp1, temp2;
    fl(j, i) {
        temp1.PB(s[j]);
    }
    fn(j, i, s.size()) {
        temp2.PB(s[j]);
    }
    temp1.PB(ch);
    s = temp1 + temp2;
}

void update(string &s, map<int, char> &can_fill) {
    fl (i, s.size()-1) {
        can_fill[i+1] = other(s[i], s[i+1]);
    }
} 

void solve(){
    // code here
    d_n(n);
    d_s(s);
    // base case
    if (n == 1) {
        cout << -1 << en;
        return;
    }
    map<int, char> can_fill;
    map<int, vector<char>> inserted_till_now;
    map<char, int> char_cnt;
    char_cnt['L'] = 0, char_cnt['T'] = 0, char_cnt['I'] = 0;
    for (int i{0}; i<n-1; i++) {
        char_cnt[s[i]]++;
        can_fill[i+1] = other(s[i], s[i+1]);
    }
    char_cnt[s[n-1]]++;
    // debug(char_cnt, can_fill);
    int iter = 2 * n;
    int cnt = 0;
    vector<int> ans;
    while (iter--) {
        if (char_cnt['L'] == char_cnt['T'] and char_cnt['T'] == char_cnt['I']) {
            cout << cnt << en;
            for (auto &l: ans) {
                cout << l << en;
            }
            return;
        }
        char first_mn = first_mini(char_cnt);
        char sec_mn = second_mini(char_cnt);
        debug(s, first_mn, sec_mn);
        debug(can_fill);
        for (int i{1}; i<s.size(); i++) {
            // cerr << "hii \n";
            if (can_fill[i] == first_mn) {
                // cerr << "Inside sec_mn -> " << s << en;
                cnt++;
                ans.push_back(i);
                char_cnt[first_mn]++;
                ins(s, i, first_mn);
                update(s, can_fill);
                if (char_cnt['L'] == char_cnt['T'] and char_cnt['T'] == char_cnt['I']) {
                    goto complete;
                }
                goto done;
            }
        }
        for (int i{1}; i<s.size(); i++) {
            // cerr << "hello \n";
            // if (i == 5) cerr << "can_fill -> " << can_fill[5] << en;
            if (can_fill[i] == sec_mn) {
                // cerr << "Inside sec_mn -> " << s << en;
                cnt++;
                ans.push_back(i);
                char_cnt[sec_mn]++;
                ins(s, i, sec_mn);
                update(s, can_fill);
                if (char_cnt['L'] == char_cnt['T'] and char_cnt['T'] == char_cnt['I']) {
                    goto complete;
                }
                goto done;
            }
        }
        done:
        debug(s);
    }
    complete:
    if (char_cnt['L'] == char_cnt['T'] and char_cnt['T'] == char_cnt['I']) {
        cout << cnt << en;
        for (auto &l: ans) {
            cout << l << en;
        }
        return;
    }
    cout << -1 << en;
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